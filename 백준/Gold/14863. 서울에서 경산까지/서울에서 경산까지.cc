#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> wt, wm, bt, bm;
vector<vector<int>> dp;

void solve1() {
    cin >> n >> k;
    wt.resize(n); wm.resize(n);
    bt.resize(n); bm.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> wt[i] >> wm[i] >> bt[i] >> bm[i];
    }
}

int solve2() {
    dp.resize(n + 1, vector<int>(k + 1, -1));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j >= wt[i-1] && dp[i-1][j-wt[i-1]] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-wt[i-1]] + wm[i-1]);
            }

            if(j >= bt[i-1] && dp[i-1][j-bt[i-1]] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-bt[i-1]] + bm[i-1]);
            }
        }
    }

    int mx = 0;
    for(int j = 0; j <= k; j++) {
        mx = max(mx, dp[n][j]);
    }

    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve1();
    cout << solve2() << '\n';

    return 0;
}