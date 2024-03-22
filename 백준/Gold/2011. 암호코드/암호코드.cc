#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int dp[5001] = {0};

    s = " " + s;
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int a = s[i] - '0';
        if (1 <= a && a <= 9) {
            dp[i] = (dp[i] + dp[i-1]) % 1000000;
        }

        if (i == 1) continue;

        int b = (s[i-1] - '0') * 10 + a;
        if (10 <= b && b <= 26) {
            dp[i] = (dp[i] + dp[i-2]) % 1000000;
        }
    }

    cout << dp[n] << endl;

    return 0;
}