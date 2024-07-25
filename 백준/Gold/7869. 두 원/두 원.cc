#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
    io;
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double area = 0.0;

    if (d >= r1 + r2) {
        area = 0.0;
    } else if (d <= abs(r1 - r2)) {
        area = M_PI * min(r1, r2) * min(r1, r2);
    } else {
        double angle1 = 2 * acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        double angle2 = 2 * acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));

        area = r1 * r1 * (angle1 - sin(angle1)) / 2 + r2 * r2 * (angle2 - sin(angle2)) / 2;
    }

    cout << fixed << setprecision(3) << area << endl;

    return 0;
}