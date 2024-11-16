#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s, d;
    cin >> s >> d;

    if ((s + d) % 2 != 0 || (s - d) % 2 != 0 || s < d) {
        cout << -1;
        return 0;
    }

    int a = (s + d) / 2;
    int b = (s - d) / 2;

    if (a < 0 || b < 0) {
        cout << -1;
        return 0;
    }

    cout << a << " " << b;

    return 0;
}