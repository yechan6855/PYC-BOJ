#include <bits/stdc++.h>
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vvi ans(m, vi(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ans[i][j];
        }
    }

    vvi dp(n, vi(m, 0));

    for (int i = 0; i < m; ++i) {
        dp[0][i] = ans[i][0];
    }

    for (int d = 1; d < n; ++d) {
        for (int des = 0; des < m; ++des) {
            int max_s = 0;
            for (int pre = 0; pre < m; ++pre) {
                int cur = dp[d - 1][pre];
                if (pre == des) {
                    cur += ans[des][d] / 2;
                } else {
                    cur += ans[des][d];
                }
                max_s = max(max_s, cur);
            }
            dp[d][des] = max_s;
        }
    }

    int res = 0;
    for (int i = 0; i < m; ++i) {
        res = max(res, dp[n-1][i]);
    }

    cout << res << endl;

    return 0;
}