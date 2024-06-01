#include <iostream>
#define ll long long
#define MOD 1000000007
#define endl "\n"
using namespace std;

ll fact[4000001];
ll inv_fact[4000001];

ll pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fact[i] = fact[i-1] * i % MOD;
    }
    
    inv_fact[n] = pow(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
    
    ll binomial_coefficient = fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    cout << binomial_coefficient << endl;

    return 0;
}