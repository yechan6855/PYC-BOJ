#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

struct Point {
    int x, y;
    Point(int x=0, int y=0): x(x), y(y) {}
    bool operator <(const Point& p) const {
        return y == p.y ? x < p.x : y < p.y;
    }
};

int cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int distSq(const Point& p1, const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool polarCompare(const Point& p1, const Point& p2, const Point& pivot) {
    int orientation = cross(pivot, p1, p2);
    if (orientation == 0) {
        return distSq(pivot, p1) < distSq(pivot, p2);
    }
    return orientation > 0;
}

int32_t main() {
    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    swap(points[0], *min_element(points.begin(), points.end()));

    sort(points.begin() + 1, points.end(),
         [&](const Point& a, const Point& b) {
             return polarCompare(a, b, points[0]);
         });

    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < N; ++i) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    cout << hull.size() << endl;

    return 0;
}