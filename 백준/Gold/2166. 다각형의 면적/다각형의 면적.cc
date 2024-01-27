#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

double calculateArea(const vector<Point>& polygon) {
    int n = polygon.size();
    double area = 0;

    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;
        area += (polygon[i].x * polygon[next].y - polygon[next].x * polygon[i].y);
    }

    area = abs(area) / 2.0;
    return area;
}

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);

    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    double result = calculateArea(polygon);

    cout << fixed;
    cout.precision(1);
    cout << result << endl;

    return 0;
}