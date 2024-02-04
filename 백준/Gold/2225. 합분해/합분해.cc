#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000000;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

    for (int i = 0; i <= N; ++i) {
        dp[1][i] = 1;
    }

    for (int k = 2; k <= K; ++k) {
        for (int n = 0; n <= N; ++n) {
            for (int l = 0; l <= n; ++l) {
                dp[k][n] = (dp[k][n] + dp[k - 1][n - l]) % MOD;
            }
        }
    }
    cout << dp[K][N] << endl;

    return 0;
}