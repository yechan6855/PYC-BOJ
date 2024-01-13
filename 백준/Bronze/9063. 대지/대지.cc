#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    int minX = points[0].first, maxX = points[n - 1].first;
    int minY = 10001, maxY = -10001;

    for (int i = 0; i < n; ++i) {
        minY = min(minY, points[i].second);
        maxY = max(maxY, points[i].second);
    }

    long long area = 1LL * (maxX - minX) * (maxY - minY);

    cout << area << endl;

    return 0;
}
