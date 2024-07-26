#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
};

ll cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point>& points) {
    int n = points.size();
    if (n <= 3) return points;

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    vector<Point> hull;
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    int lower_hull = hull.size();
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() > lower_hull && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back();
    return hull;
}

ll dist(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll rotating_calipers(const vector<Point>& hull) {
    int n = hull.size();
    if (n <= 1) return 0;
    if (n == 2) return dist(hull[0], hull[1]);

    ll max_dist = 0;
    int j = 1;
    for (int i = 0; i < n; ++i) {
        while (dist(hull[i], hull[(j + 1) % n]) > dist(hull[i], hull[j])) {
            j = (j + 1) % n;
        }
        max_dist = max(max_dist, dist(hull[i], hull[j]));
    }
    return max_dist;
}

int main() {
    io
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convex_hull(points);
    ll ans = rotating_calipers(hull);

    cout << ans << endl;

    return 0;
}