#include <iostream>
#include <vector>

using namespace std;

// 특정 수를 1로 만들기 위한 최소 연산과 그 순서를 출력하는 함수
void makeOne(int n) {
    vector<int> dp(n + 1, 0);  // dp[i]: 숫자 i를 1로 만들기 위한 최소 연산 횟수
    vector<int> prev(n + 1, 0);  // prev[i]: 숫자 i를 만들기 위한 직전의 숫자

    for (int i = 2; i <= n; ++i) {
        // 1을 더하는 경우
        dp[i] = dp[i - 1] + 1;
        prev[i] = i - 1;

        // 2로 나누어 떨어지는 경우
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            prev[i] = i / 2;
        }
        // 3으로 나누어 떨어지는 경우
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            prev[i] = i / 3;
        }
    }
    cout << dp[n] << '\n';

    // 최소 연산 순서 출력
    int current = n;
    while (current != 0) {
        cout << current << ' ';
        current = prev[current];
    }
}
int main() {
    int n;
    cin >> n;

    makeOne(n);

    return 0;
}