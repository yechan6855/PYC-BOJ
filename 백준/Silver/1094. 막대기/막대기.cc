#include <iostream>

using namespace std;

int main() {
    int X;
    int cnt = 0;
    cin >> X;

    while (X > 0) {
        if (X % 2 == 1) {
            cnt++;
        }
        X /= 2;
    }
    cout << cnt << "\n";
    return 0;
}