#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

struct Point {
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
    bool operator < (const Point &p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
};

long long ccw(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n <= 3) return points;

    sort(points.begin(), points.end());
    vector<Point> lower, upper;

    for (int i = 0; i < n; i++) {
        while (lower.size() >= 2 && ccw(lower[lower.size()-2], lower.back(), points[i]) <= 0)
            lower.pop_back();
        lower.push_back(points[i]);
    }

    for (int i = n-1; i >= 0; i--) {
        while (upper.size() >= 2 && ccw(upper[upper.size()-2], upper.back(), points[i]) <= 0)
            upper.pop_back();
        upper.push_back(points[i]);
    }

    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

bool onSegment(const Point& p, const Point& q, const Point& r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

int orientation(const Point& p, const Point& q, const Point& r) {
    long long val = ccw(p, q, r);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool segmentIntersect(const Point& p1, const Point& q1, const Point& p2, const Point& q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

bool isInside(const vector<Point>& polygon, const Point& p) {
    int n = polygon.size();
    if (n < 3) return false;

    Point extreme(1e9, p.y);
    int count = 0, i = 0;
    do {
        int next = (i + 1) % n;
        if (segmentIntersect(polygon[i], polygon[next], p, extreme)) {
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], p, polygon[next]);
            count++;
        }
        i = next;
    } while (i != 0);

    return count & 1;
}

bool canSeparate(vector<Point>& black, vector<Point>& white) {
    vector<Point> blackHull = convexHull(black);
    vector<Point> whiteHull = convexHull(white);

    for (int i = 0; i < blackHull.size(); i++) {
        for (int j = 0; j < whiteHull.size(); j++) {
            if (segmentIntersect(blackHull[i], blackHull[(i+1)%blackHull.size()],
                                 whiteHull[j], whiteHull[(j+1)%whiteHull.size()])) {
                return false;
            }
        }
    }

    if (!blackHull.empty() && isInside(whiteHull, blackHull[0])) return false;
    if (!whiteHull.empty() && isInside(blackHull, whiteHull[0])) return false;

    return true;
}

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<Point> black(n), white(m);

        for (int i = 0; i < n; i++) cin >> black[i].x >> black[i].y;
        for (int i = 0; i < m; i++) cin >> white[i].x >> white[i].y;

        cout << (canSeparate(black, white) ? "YES" : "NO") << endl;
    }
    return 0;
}