#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int ac = 0, bc = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            ac++;
        } else {
            bc++;
        }
    }
    cout << ac << " : " << bc;
}