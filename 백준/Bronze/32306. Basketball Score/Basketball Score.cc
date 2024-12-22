#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a1, b1, c1;
    int a2, b2, c2;

    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    int a = a1 * 1 + b1 * 2 + c1 * 3;
    int b = a2 * 1 + b2 * 2 + c2 * 3;

    if (a > b) {
        cout << 1 << endl;
    } else if (b > a) {
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}