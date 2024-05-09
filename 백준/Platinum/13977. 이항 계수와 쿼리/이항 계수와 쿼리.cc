#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 4000000;

vector<int> fact(MAX_N + 1);
vector<int> inv_fact(MAX_N + 1);

int modExp(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void Factorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAX_N] = modExp(fact[MAX_N], MOD - 2, MOD);
    for (int i = MAX_N - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Factorials();

    int M, N, K;
    cin >> M;
    while (M--) {
        cin >> N >> K;
        if (K > N) {
            cout << 0 << endl;
        } else {
            int result = fact[N] * inv_fact[K] % MOD * inv_fact[N - K] % MOD;
            cout << result << endl;
        }
    }

    return 0;
}