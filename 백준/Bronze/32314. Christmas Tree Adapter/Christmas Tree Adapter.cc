#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, w, v;

    cin >> a >> w >> v;

    int x = w / v;

    if (x >= a) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}