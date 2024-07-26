#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct Point {
    int x, y;
};

bool compX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compY(const Point& a, const Point& b) {
    return a.y < b.y;
}

int dist(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int bruteForce(vector<Point>& points, int left, int right) {
    int minDist = INT_MAX;
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j <= right; j++) {
            minDist = min(minDist, dist(points[i], points[j]));
        }
    }
    return minDist;
}

int stripClosest(vector<Point>& strip, int size, int d) {
    int minDist = d;
    sort(strip.begin(), strip.end(), compY);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < minDist; j++) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}

int closestUtil(vector<Point>& points, int left, int right) {
    if (right - left <= 3) {
        return bruteForce(points, left, right);
    }

    int mid = (left + right) / 2;
    int dl = closestUtil(points, left, mid);
    int dr = closestUtil(points, mid + 1, right);
    int d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - points[mid].x) * abs(points[i].x - points[mid].x) < d) {
            strip.push_back(points[i]);
        }
    }

    return min(d, stripClosest(strip, strip.size(), d));
}

int closest(vector<Point>& points) {
    sort(points.begin(), points.end(), compX);
    return closestUtil(points, 0, points.size() - 1);
}

int main() {
    io;
    int n;
    cin >> n;

    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    cout << closest(p) << endl;

    return 0;
}