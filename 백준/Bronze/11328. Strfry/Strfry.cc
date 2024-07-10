#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
    io;
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string s1, s2;
        getline(cin, s1, ' ');
        getline(cin, s2);

        if (s1.length() != s2.length()) {
            cout << "Impossible" << endl;
            continue;
        }

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if (s1 == s2) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}