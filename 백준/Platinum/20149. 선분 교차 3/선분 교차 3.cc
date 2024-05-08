#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define X first
#define Y second
#define pll pair<ll, ll>
using namespace std;

ll x, y;
vector<pll> v;

ll CCW(pll A, pll B, pll C) {
    ll tmp = A.X * B.Y + B.X * C.Y + C.X * A.Y;
    tmp -= B.X * A.Y + C.X * B.Y + A.X * C.Y;
    if (tmp > 0) return 1;
    else if (tmp == 0) return 0;
    else return -1;
}

void findIntersection(pll A, pll B, pll C, pll D) {
    ll A1 = B.Y - A.Y;
    ll B1 = A.X - B.X;
    ll C1 = A1 * A.X + B1 * A.Y;

    ll A2 = D.Y - C.Y;
    ll B2 = C.X - D.X;
    ll C2 = A2 * C.X + B2 * C.Y;

    ll determinant = A1 * B2 - A2 * B1;
    if (determinant!=0) {
        double x = (B2 * C1 - B1 * C2) / (double) determinant;
        double y = (A1 * C2 - A2 * C1) / (double) determinant;
        cout << fixed << setprecision(9) << x << " " << y << endl;
    }
}

int solve(pll A, pll B, pll C, pll D) {
    ll ans1 = CCW(A, B, C) * CCW(A, B, D);
    ll ans2 = CCW(C, D, A) * CCW(C, D, B);
    if (ans1 == 0 && ans2 == 0) {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        if (A <= D && B >= C) {
            cout << "1" << endl;
            if (A == D || B == C) {
                // Print the overlapping point
                if (A == D) cout << A.X << " " << A.Y << endl;
                else cout << B.X << " " << B.Y << endl;
            } else {
                findIntersection(A, B, C, D);
            }
            return 1;
        } else {
            return 0;
        }
    } else {
        if (ans1 <= 0 && ans2 <= 0) {
            cout << "1" << endl;
            findIntersection(A, B, C, D);
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        v.push_back({ x,y });
    }
    int result = solve(v[0], v[1], v[2], v[3]);
    if (result == 0) {
        cout << "0" << endl;
    }
    return 0;
}