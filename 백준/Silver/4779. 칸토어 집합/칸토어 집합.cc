#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    int len = pow(3, n);
    if (n == 0) {
        cout << "-";
        return;
    }

    solve(n-1);
    for (int i = 0; i < len/3; i++) {
        cout << " ";
    }
    solve(n-1);
}

int main() {
    int n;
    while (cin >> n) {
        solve(n);
        cout << "\n";
    }
    return 0;
}