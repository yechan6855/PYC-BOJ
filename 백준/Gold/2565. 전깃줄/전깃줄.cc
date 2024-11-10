#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<int, int>> l(n);
    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++) {
        cin >> l[i].X >> l[i].Y;
    }

    sort(l.begin(), l.end());

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(l[i].Y > l[j].Y) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << n - ans << endl;

    return 0;
}