#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> c(53, vector<int>(53, 1));
    for (int n = 1; n <= 52; n++) {
        for (int k = 1; k < n; k++) {
            c[n][k] = (c[n-1][k-1] + c[n-1][k]) % 10007;
        }
    }

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 4; i <= n; i += 4) {
        if ((i/4) & 1) {
            ans += c[13][i/4] * c[52-i][n-i];
        } else {
            ans -= c[13][i/4] * c[52-i][n-i];
        }
        ans %= 10007;
    }
    cout << (ans + 10007) % 10007;

    return 0;
}