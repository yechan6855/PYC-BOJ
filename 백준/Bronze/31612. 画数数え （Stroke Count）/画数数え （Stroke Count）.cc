#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;

    cin >> N;
    cin >> S;

    int ans = 0;

    for (char c : S) {
        if (c == 'j') ans += 2;
        else if (c == 'o') ans += 1;
        else if (c == 'i') ans += 2;
    }

    cout << ans << "\n";

    return 0;
}