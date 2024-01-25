#include <iostream>
#include <vector>
using namespace std;

// 조합의 개수를 계산하는 함수
int binomialCoeff(int n, int r, vector<vector<int>>& dp) {
    if (r == 0 || r == n) {
        return 1;
    }

    if (dp[n][r] != -1) {
        return dp[n][r];
    }

    dp[n][r] = min(binomialCoeff(n - 1, r - 1, dp) + binomialCoeff(n - 1, r, dp), static_cast<int>(1e9));
    return dp[n][r];
}

// k번째 사전 단어를 찾는 DP 함수
string findKthWord(int n, int m, long long k, vector<vector<int>>& dp) {
    if (k > binomialCoeff(n + m, n, dp)) {
        return "-1";
    }

    string result;
    int a = n, z = m;

    while (a > 0 && z > 0) {
        // 'a'를 선택할 경우의 경우의 수
        long long count = binomialCoeff(a + z - 1, a - 1, dp);

        if (k <= count) {
            result += 'a';
            --a;
        } else {
            result += 'z';
            k -= count;
            --z;
        }
    }

    // 남은 문자열 처리
    while (a > 0) {
        result += 'a';
        --a;
    }

    while (z > 0) {
        result += 'z';
        --z;
    }

    return result;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    // dp 배열 초기화
    vector<vector<int>> dp(n + m + 1, vector<int>(n + 1, -1));

    string answer = findKthWord(n, m, k, dp);
    cout << answer << endl;

    return 0;
}