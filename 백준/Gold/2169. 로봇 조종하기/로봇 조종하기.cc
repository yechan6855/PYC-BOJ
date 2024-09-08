#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    vector<vector<int>> dp(N, vector<int>(M));
    vector<int> ltr(M), rtl(M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    dp[0][0] = map[0][0];
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j-1] + map[0][j];
    }

    for (int i = 1; i < N; i++) {
        ltr[0] = dp[i - 1][0] + map[i][0];
        for (int j = 1; j < M; j++) {
            ltr[j] = max(dp[i - 1][j], ltr[j - 1]) + map[i][j];
        }

        rtl[M - 1] = dp[i - 1][M - 1] + map[i][M - 1];
        for (int j = M-2; j >= 0; j--) {
            rtl[j] = max(dp[i - 1][j], rtl[j + 1]) + map[i][j];
        }

        for (int j = 0; j < M; j++) {
            dp[i][j] = max(ltr[j], rtl[j]);
        }
    }

    cout << dp[N-1][M-1] << endl;

    return 0;
}