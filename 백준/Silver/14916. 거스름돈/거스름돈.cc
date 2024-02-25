#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n % 5 != 0) {
        n -= 2;
        cnt++;
        if (n < 0) {
            cout << -1;
            return 0;
        }
    }
    cout << cnt + n / 5;
}