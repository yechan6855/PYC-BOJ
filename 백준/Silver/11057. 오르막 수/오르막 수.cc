#include <bits/stdc++.h>
#define ll long long
#define MOD 10007
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(10, 1);

    for (int i = 2; i <= n; i++) {
        vector<int> temp(10, 0);
        temp[0] = dp[0];
        for (int j = 1; j <= 9; j++) {
            temp[j] = (temp[j - 1] + dp[j]) % MOD;
        }
        dp = temp;
    }

    int ans = 0;

    for (int j = 0; j <= 9; j++) {
        ans = (ans + dp[j]) % MOD;
    }

    cout << ans;
}