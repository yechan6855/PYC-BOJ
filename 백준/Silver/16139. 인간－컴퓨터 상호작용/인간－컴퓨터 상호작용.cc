#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    io;
    string s;
    int t;
    cin >> s >> t;

    vvi pre(26, vi(s.size() + 1, 0));

    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            pre[j][i + 1] = pre[j][i];
        }
        pre[s[i] - 'a'][i + 1]++;
    }

    while (t--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        int idx = c - 'a';
        int ans = pre[idx][r + 1] - pre[idx][l];
        cout << ans << endl;
    }

    return 0;
}