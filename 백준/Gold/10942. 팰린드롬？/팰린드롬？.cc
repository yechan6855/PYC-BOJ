#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) dp[i][i] = true;

    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] == arr[i + 1]) dp[i][i + 1] = true;
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (arr[i] == arr[j] && dp[i + 1][j - 1]) dp[i][j] = true;
        }
    }

    int m, s, e;
    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << (dp[s - 1][e - 1] ? 1 : 0) << '\n';
    }

    return 0;
}