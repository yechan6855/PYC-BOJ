#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1000001;
const double PI = acos(-1);

vector<int> primes;
bool is_prime[MAX];
vector<ll> semi_primes(MAX);

void sieve() {
    fill(is_prime, is_prime + MAX, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void calc_semi_primes() {
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            ll prod = (ll)primes[i] * primes[j];
            if (prod >= MAX) break;
            semi_primes[prod]++;
        }
    }
}

struct Complex {
    double real, imag;
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& c) const { return Complex(real + c.real, imag + c.imag); }
    Complex operator-(const Complex& c) const { return Complex(real - c.real, imag - c.imag); }
    Complex operator*(const Complex& c) const { return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real); }
};

void fft(vector<Complex>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        Complex wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            Complex w(1);
            for (int j = 0; j < len / 2; j++) {
                Complex u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }
    if (invert) {
        for (auto& x : a) x.real /= n;
    }
}

vector<ll> multiply(const vector<ll>& a, const vector<ll>& b) {
    vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] = fa[i] * fb[i];
    fft(fa, true);
    vector<ll> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    calc_semi_primes();

    vector<ll> odd_primes(MAX), even_semi_primes(MAX);
    for (int i = 3; i < MAX; i += 2) {
        if (is_prime[i]) odd_primes[i] = 1;
    }
    for (int i = 2; i < MAX; i += 2) {
        even_semi_primes[i] = semi_primes[i];
    }

    vector<ll> result = multiply(odd_primes, even_semi_primes);

    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cout << result[N] << '\n';
    }

    return 0;
}