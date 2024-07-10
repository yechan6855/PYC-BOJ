#include <bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MOD = 1000000009;
const int MAX_N = 100000;

vector<int> dp(MAX_N + 1, 0);
vector<int> dp1(MAX_N + 1, 0);
vector<int> dp2(MAX_N + 1, 0);
vector<int> dp3(MAX_N + 1, 0);

void solve() {
    dp[0] = 1;
    if (MAX_N >= 1) dp1[1] = 1;
    if (MAX_N >= 2) dp1[2] = 1, dp2[2] = 1;
    if (MAX_N >= 3) dp1[3] = 2, dp3[3] = 1;

    for (int i = 1; i <= MAX_N; ++i) {
        if (i > 1) {
            dp1[i] = (dp2[i-1] + dp3[i-1]) % MOD;
        }
        if (i > 2) {
            dp2[i] = (dp1[i-2] + dp3[i-2]) % MOD;
        }
        if (i > 3) {
            dp3[i] = (dp1[i-3] + dp2[i-3]) % MOD;
        }
        dp[i] = (dp1[i] + dp2[i] + dp3[i]) % MOD;
    }
}

int32_t main() {
    io;
    solve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] % MOD << endl;
    }
    return 0;
}