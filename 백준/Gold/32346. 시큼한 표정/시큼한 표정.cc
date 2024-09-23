#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll power_mod(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1LL) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1LL;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int MAX = 4000;
    vector<long long> fact(MAX + 1, 1);
    for (int i = 1; i <= MAX; i++) fact[i] = fact[i - 1] * i % MOD;

    vector<long long> inv_fact(MAX + 1, 1);
    inv_fact[MAX] = power_mod(fact[MAX], MOD - 2, MOD);
    for (int i = MAX - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    auto bin = [&](int n, int k) -> ll {
        if (n < 0 || k < 0 || k > n) return 0;
        return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    };

    ll answer = 0;

    for (int k = 1; k <= n / 2; k++) {
        for (int i = 0; i + 2 * k <= n; i++) {
            bool flag = true;

            for (int p = i; p < i + k; p++) {
                if (s[p] != '>') {
                    flag = false;
                    break;
                }
            }

            if (!flag) continue;

            for (int p = i + k; p < i + 2 * k; p++) {
                if (s[p] != '<') {
                    flag = false;
                    break;
                }
            }

            if (!flag) continue;

            int a = n - 2 * k;
            int b = i;
            ll c = bin(a, b);
            answer = (answer + c) % MOD;
        }
    }

    cout << answer;
}