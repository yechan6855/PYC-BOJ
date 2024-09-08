#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, R;
    cin >> N >> L >> R;

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(L + 1, vector<ll>(R + 1, 0)));

    dp[1][1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            for (int k = 1; k <= R; k++) {
                dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][k]) % MOD;
                dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1]) % MOD;
                dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k] * (i-2)) % MOD;
            }
        }
    }

    cout << dp[N][L][R] << endl;

    return 0;
}