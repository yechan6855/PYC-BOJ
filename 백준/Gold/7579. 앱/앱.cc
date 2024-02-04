#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> memory(N);
    vector<int> cost(N);

    for (int i = 0; i < N; i++) {
        cin >> memory[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(10001, 0));

    int result = 10001; // 초기값으로 충분히 큰 값 설정

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (cost[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i - 1]] + memory[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }

            if (dp[i][j] >= M) {
                result = min(result, j);
            }
        }
    }
    cout << result << endl;

    return 0;
}