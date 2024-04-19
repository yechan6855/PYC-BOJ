#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<string> s;

    for (int i = 0; i < n; i++) {
        string name, stat;
        cin >> name >> stat;

        if (stat == "enter") {
            s.insert(name);
        } else if (stat == "leave") {
            s.erase(name);
        }
    }
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << endl;
    }
    return 0;
}