#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            double d1 = sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2));
            double d2 = sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2));
            if ((d1 < r && d2 > r) || (d1 > r && d2 < r)) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}