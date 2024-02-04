#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        vector<int> files(K + 1);
        vector<int> sum(K + 1, 0);
        vector<vector<int>> dp(K + 1, vector<int>(K + 1, 0));

        for (int i = 1; i <= K; ++i) {
            cin >> files[i];
            sum[i] = sum[i - 1] + files[i];
        }

        for (int len = 1; len < K; ++len) {
            for (int i = 1; i + len <= K; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }

        cout << dp[1][K] << "\n";
    }
    return 0;
}