#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 0;
    int r = n - 1;
    int m = 2e9;
    int x = 0, y = 0;

    while (l < r) {
        int s = a[l] + a[r];

        if (abs(s) < m) {
            m = abs(s);
            x = a[l];
            y = a[r];
        }

        if (s < 0) {
            l++;
        } else {
            r--;
        }
    }

    cout << x << " " << y << "\n";

    return 0;
}