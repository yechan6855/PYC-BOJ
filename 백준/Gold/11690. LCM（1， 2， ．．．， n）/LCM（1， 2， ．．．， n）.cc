#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define qi queue<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

const int MOD = 4294967296ULL;

vi sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vi primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.pb(i);
        }
    }
    return primes;
}

int32_t main() {
    io;

    int n;
    cin >> n;

    vi primes = sieve(n);
    int result = 1;

    for (int prime : primes) {
        int p = prime;
        while (p * prime <= n) {
            p *= prime;
        }
        result = (result * p) % MOD;
    }

    cout << result << endl;
    return 0;
}