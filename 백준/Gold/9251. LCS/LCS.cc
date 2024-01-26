#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();
    
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                // 현재 문자가 같다면, 이전 문자까지의 LCS 길이에 1을 더해준다.
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // 현재 문자가 다르다면, 이전에서의 LCS 중에서 더 큰 값을 가져온다.
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // str1과 str2의 LCS 길이 출력
    cout << dp[len1][len2] << endl;

    return 0;
}