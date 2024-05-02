#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//-----------------------------------------------------------
void solve(void) {
    const string str[7] = {
            "Never gonna give you up",
            "Never gonna let you down",
            "Never gonna run around and desert you",
            "Never gonna make you cry",
            "Never gonna say goodbye",
            "Never gonna tell a lie and hurt you",
            "Never gonna stop"
    };

    int n; cin >> n;
    cin.ignore();
    vector<string> s(n);
    for (int i=0; i<n; i++) getline(cin, s[i]);

    for (int i=0; i<n; i++) {
        bool flag = false;
        for (int j=0; j<7; j++) {
            if (s[i] == str[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}
//-----------------------------------------------------------
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
//-----------------------------------------------------------