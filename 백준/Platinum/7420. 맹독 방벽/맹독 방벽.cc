#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Point {
    int x, y;
};

bool compare(Point a, Point b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double distance(Point a, Point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int main() {
    int N, L;
    cin >> N >> L;

    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), compare);

    vector<Point> hull;

    for (int i = 0; i < N; i++) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    for (int i = N - 2, t = hull.size() + 1; i >= 0; i--) {
        while (hull.size() >= t && ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back();

    double perimeter = 0;
    for (int i = 0; i < hull.size(); i++) {
        perimeter += distance(hull[i], hull[(i + 1) % hull.size()]);
    }

    perimeter += 2 * M_PI * L;

    cout << round(perimeter) << endl;

    return 0;
}