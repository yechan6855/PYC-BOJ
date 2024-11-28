#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<string> ans;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ans.insert(s);
    }

    cout << ans.size() << endl;

    return 0;
}