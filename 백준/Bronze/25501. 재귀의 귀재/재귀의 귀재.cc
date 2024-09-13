#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int cnt;

int recursion(const string& s, int l, int r) {
    cnt++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPal(const string& s) {
    cnt = 0;
    return recursion(s, 0, s.length() - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = isPal(s);
        cout << ans << " " << cnt << endl;
    }
    return 0;
}