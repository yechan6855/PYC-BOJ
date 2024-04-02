#include <bits/stdc++.h>

using namespace std;

struct dpnode {
    int v, h;
};

int main()
{
    int tc; cin >> tc;
    while (tc--) {
        int n, k; cin >> n >> k;
        vector<vector<vector<int>>> arr(4, vector<vector<int>>(n + 1, vector<int>(3, 2100000000)));

        for (int i = 1; i <= n; i++) {
            cin >> arr[0][i][1];
        }
        for (int i = 1; i <= n; i++) {
            cin >> arr[0][i][2];
        }

        arr[1] = arr[0];
        arr[2] = arr[0];
        arr[3] = arr[0];

        arr[1].push_back(arr[1][1]);
        arr[2].push_back(arr[2][1]);
        arr[3].push_back(arr[3][1]);
        
        arr[1][1][1] = k + 1;
        arr[1][n + 1][2] = k + 1;
        arr[2][1][2] = k + 1;
        arr[2][n + 1][1] = k + 1;
        arr[3][1][1] = k + 1;
        arr[3][1][2] = k + 1;

        int mx = -1;

        for (int r = 0; r < 4; r++) {
            int lim = n + (r > 0 ? 1 : 0);
            vector<vector<dpnode>> dp(lim + 1, vector<dpnode>(3));
            vector<int> dpt(lim + 1);
            
            dp[1][1].v = (arr[r][1][1] + arr[r][1][2] <= k ? 1 : 0);
            dp[1][2].v = (arr[r][1][1] + arr[r][1][2] <= k ? 1 : 0);
            dpt[1] = (arr[r][1][1] + arr[r][1][2] <= k ? 1 : 0);
            
            for (int i = 2; i <= lim; i++) {
                int s1 = 0, s21 = 0, s22 = 0;
                s1 = dpt[i - 1] + (arr[r][i][1] + arr[r][i][2] <= k ? 1 : 0);
                
                int p1 = (arr[r][i - 1][1] + arr[r][i][1] <= k) ? 1 : 0;
                int p2 = (arr[r][i - 1][2] + arr[r][i][2] <= k) ? 1 : 0;
                
                s21 = (dpt[i - 2] > dp[i - 1][2].h ? dpt[i - 2] : dp[i - 1][2].h) + p1;
                
                dp[i][1].h = s21;
                dp[i][1].v = s1;
                
                s22 = (dpt[i - 2] > dp[i - 1][1].h ? dpt[i - 2] : dp[i - 1][1].h) + p2;
                
                dp[i][2].h = s22;
                dp[i][2].v = s1;
                dpt[i] = max({dp[i][1].h, dp[i][1].v, dp[i][2].h, dp[i][2].v, dpt[i - 2] + p1 + p2});
            }
            mx = (mx > dpt[lim] ? mx : dpt[lim]);
        }
        cout << n * 2 - mx << "\n";
    }
    return 0;
}