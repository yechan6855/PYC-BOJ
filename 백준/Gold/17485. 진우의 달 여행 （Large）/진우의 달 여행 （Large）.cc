#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define MOD 1000000007
using namespace std;

const int INF = INT_MAX;

signed main() {
    int N, M;
    cin >> N >> M;

    vvi fuel(N, vi(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> fuel[i][j];
        }
    }

    vvvi dp(N, vvi(M, vi(3, INF)));

    for (int j = 0; j < M; ++j) {
        dp[0][j][0] = fuel[0][j];
        dp[0][j][1] = fuel[0][j];
        dp[0][j][2] = fuel[0][j];
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j > 0) {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][1] + fuel[i][j]);
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][2] + fuel[i][j]);
            }
            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] + fuel[i][j]);
            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][2] + fuel[i][j]);
            if (j < M - 1) {
                dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j + 1][0] + fuel[i][j]);
                dp[i][j][2] = min(dp[i][j][2], dp[i - 1][j + 1][1] + fuel[i][j]);
            }
        }
    }

    int minFuel = INF;
    for (int j = 0; j < M; ++j) {
        minFuel = min(minFuel, dp[N-1][j][0]);
        minFuel = min(minFuel, dp[N-1][j][1]);
        minFuel = min(minFuel, dp[N-1][j][2]);
    }

    cout << minFuel << endl;

    return 0;
}