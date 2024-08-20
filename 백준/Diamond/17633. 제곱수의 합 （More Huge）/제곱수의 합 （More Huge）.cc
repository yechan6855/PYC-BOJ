#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll modmul(ll a, ll b, ll mod) {
    ll result = 0;
    a = a % mod;
    while (b) {
        if (b % 2 == 1) result = (result + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return result;
}

ll modpow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp) {
        if (exp % 2 == 1) result = modmul(result, base, mod);
        exp = exp >> 1;
        base = modmul(base, base, mod);
    }
    return result;
}

bool miller_rabin(ll n, ll a) {
    if (n % a == 0) return false;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    ll x = modpow(a, d, n);
    if (x == 1 || x == n - 1) return true;
    while (d != n - 1) {
        x = modmul(x, x, n);
        d *= 2;
        if (x == n - 1) return true;
    }
    return false;
}

bool is_prime(ll n) {
    if (n < 2) return false;
    if (n != 2 && n % 2 == 0) return false;
    vector<ll> test_bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (ll a : test_bases) {
        if (a >= n) break;
        if (!miller_rabin(n, a)) return false;
    }
    return true;
}

ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    ll x = 2, y = 2, d = 1;
    ll c = rand() % n + 1;
    while (d == 1) {
        x = (modmul(x, x, n) + c + n) % n;
        y = (modmul(y, y, n) + c + n) % n;
        y = (modmul(y, y, n) + c + n) % n;
        d = std::gcd((ll)abs(x - y), n);
    }
    return d;
}

void factorize(ll n, unordered_map<ll, int>& factors) {
    if (n == 1) return;
    if (is_prime(n)) {
        factors[n]++;
        return;
    }
    ll divisor = pollard_rho(n);
    factorize(divisor, factors);
    factorize(n / divisor, factors);
}

bool isSquare(ll n) {
    ll sq = (ll)std::sqrt(n);
    return sq * sq == n;
}

bool isFour(ll n) {
    while (n % 4 == 0) n /= 4;
    return n % 8 == 7;
}

bool isTwo(ll n) {
    unordered_map<ll, int> factors;
    factorize(n, factors);
    for (auto& [p, exp] : factors) {
        if (p % 4 == 3 && exp % 2 != 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;

    if (isSquare(n)) {
        cout << 1 << endl;
        return 0;
    }

    if (isFour(n)) {
        cout << 4 << endl;
        return 0;
    }

    if (isTwo(n)) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }

    return 0;
}