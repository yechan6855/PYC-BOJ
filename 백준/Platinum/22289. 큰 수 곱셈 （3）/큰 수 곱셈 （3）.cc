#include <bits/stdc++.h>
#define ll long long
#define cd complex<double>
using namespace std;

const double PI = acos(-1.0);

void fft(vector<cd > &a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        if (j < bit) j += bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (auto &x: a) {
            x /= n;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    vector<int> num1, num2;

    for (auto it = s1.rbegin(); it != s1.rend(); ++it) {
        num1.push_back(*it - '0');
    }

    for (auto it = s2.rbegin(); it != s2.rend(); ++it) {
        num2.push_back(*it - '0');
    }

    int n = 1;

    while (n < num1.size() + num2.size()) {
        n <<= 1;
    }

    vector<cd > a(n, 0), b(n, 0);

    for (int i = 0; i < num1.size(); ++i) {
        a[i] = num1[i];
    }

    for (int i = 0; i < num2.size(); ++i) {
        b[i] = num2[i];
    }

    fft(a, false);
    fft(b, false);

    for (int i = 0; i < n; ++i) {
        a[i] *= b[i];
    }

    fft(a, true);

    vector<ll> res(n, 0);
    for (int i = 0; i < n; ++i)
        res[i] = round(a[i].real());

    ll carry = 0;

    for (int i = 0; i < n; ++i) {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }

    int size = n;

    while (size > 1 && res[size - 1] == 0) {
        size--;
    }

    string product = "";
    for (int i = size - 1; i >= 0; --i) {
        product += to_string((int) res[i]);
    }

    cout << product;
}