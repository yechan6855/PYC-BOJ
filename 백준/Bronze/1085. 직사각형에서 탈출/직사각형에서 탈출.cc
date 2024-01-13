#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int distance_x = min(x, w - x);
    int distance_y = min(y, h - y);

    int result = min(distance_x, distance_y);

    cout << result << endl;
}
