#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // 입력 받기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> cost[i][j];
        }
    }

    // 다이나믹 프로그래밍
    for (int i = 0; i < 3; ++i) {
        dp[0][i] = cost[0][i];
    }

    for (int i = 1; i < n; ++i) {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    // 최종 결과 출력
    int result = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    cout << result << endl;

    return 0;
}