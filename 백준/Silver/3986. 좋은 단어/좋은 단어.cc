#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
    io;
    int n;
    cin >> n;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        string st;
        cin >> st;
        stack<char> s;

        for (char c : st) {
            if (!s.empty() && s.top() == c) {
                s.pop();
            } else {
                s.push(c);
            }
        }

        if (s.empty()) {
            ++cnt;
        }
    }

    cout << cnt << endl;
}