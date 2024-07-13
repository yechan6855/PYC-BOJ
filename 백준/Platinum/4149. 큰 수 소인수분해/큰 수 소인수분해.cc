#include <bits/stdc++.h>
#include <random>
#define ll long long
#define i128 __int128
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

i128 mul(i128 a, i128 b, i128 m) {
    return (a * b) % m;
}

i128 power(i128 a, i128 b, i128 m) {
    i128 r = 1;
    a %= m;
    while (b) {
        if (b & 1) r = mul(r, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return r;
}

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

bool miller_rabin(ll n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    ll d = n - 1, s = 0;
    while (d % 2 == 0) d >>= 1, s++;

    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n <= a) break;
        i128 x = power(a, d, n);
        if (x == 1 || x == n-1) continue;
        bool composite = true;
        for (int i = 0; i < s-1; i++) {
            x = mul(x, x, n);
            if (x == n-1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    if (miller_rabin(n)) return n;

    ll c = uniform_int_distribution<ll>(1, n-1)(rng);
    auto f = [&](i128 x) { return (mul(x, x, n) + c) % n; };
    i128 x = uniform_int_distribution<ll>(0, n-1)(rng);
    i128 y = x;
    ll d = 1;

    while (d == 1) {
        x = f(x);
        y = f(f(y));
        d = gcd(llabs((ll)(x - y)), n);
        if (d == n) {
            c = uniform_int_distribution<ll>(1, n-1)(rng);
            x = uniform_int_distribution<ll>(0, n-1)(rng);
            y = x;
            d = 1;
        }
    }
    return d;
}

void factorize(ll n, vector<ll>& factors) {
    if (n == 1) return;
    if (miller_rabin(n)) {
        factors.push_back(n);
        return;
    }
    ll d = pollard_rho(n);
    factorize(d, factors);
    factorize(n / d, factors);
}

int main() {
    io;
    ll n;
    cin >> n;

    if (miller_rabin(n)) {
        cout << n << '\n';
    } else {
        vector<ll> factors;
        factorize(n, factors);

        sort(factors.begin(), factors.end());

        for (ll factor : factors) {
            cout << factor << '\n';
        }
    }
    
    return 0;
}