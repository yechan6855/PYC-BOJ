#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int m = a * b;
    int p = c * d;

    if (m > p) {
        cout << "M";
    } else if (m < p) {
        cout << "P";
    } else {
        cout << "E";
    }

    return 0;
}