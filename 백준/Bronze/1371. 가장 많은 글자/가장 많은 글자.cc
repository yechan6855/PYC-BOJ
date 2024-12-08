#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(26, 0);
    string s;

    while (getline(cin, s)) {
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                a[c - 'a']++;
            }
        }
    }

    int max_count = *max_element(a.begin(), a.end());

    for (int i = 0; i < 26; i++) {
        if (a[i] == max_count) {
            cout << (char)('a' + i);
        }
    }

    return 0;
}