#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double PI = acos(-1.0);

    int r;
    cin >> r;

    double euclidean = PI * r * r;
    double taxi = 2 * r * r;

    cout << fixed;
    cout.precision(6);
    cout << euclidean << '\n';
    cout << taxi << '\n';

    return 0;
}