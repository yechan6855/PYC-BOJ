#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

vector<int> solve(const string& s) {
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

int main() {
    io;
    string s;
    cin >> s;

    int n = s.length();
    if (n < 2) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> pi = solve(s);
    int ans = pi[n - 1];

    if (ans == 0) {
        cout << -1 << endl;
        return 0;
    }

    bool found = false;
    for (int i = 0; i < n - 1; ++i) {
        if (pi[i] == ans) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << s.substr(0, ans) << endl;
    } else {
        if (pi[ans - 1] == 0) {
            cout << -1 << endl;
        } else {
            cout << s.substr(0, pi[ans - 1]) << endl;
        }
    }

    return 0;
}