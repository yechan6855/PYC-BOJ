#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        vector<int> s(7);
        for (int j = 0; j < 7; j++) {
            cin >> s[j];
        }

        int res = max(s[0], s[1]);

        sort(s.begin() + 2, s.end(), greater<int>());
        int tri = s[2] + s[3];

        int fin = res + tri;
        ans = max(ans, fin);
    }

    cout << ans << "\n";

    return 0;
}