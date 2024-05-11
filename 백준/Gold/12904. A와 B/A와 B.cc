#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int32_t main() {
    string S, T;
    cin >> S >> T;

    while (T.length() > S.length()) {
        if (T.back() == 'A') {
            T.pop_back();
        } else if (T.back() == 'B') {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    if (S == T) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}