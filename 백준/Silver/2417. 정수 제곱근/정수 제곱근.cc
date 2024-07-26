#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
    io;
    ll n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    double x = n;
    double prev = 0;

    while (abs(x - prev) >= 1) {
        prev = x;
        x = (x + n / x) / 2.0;
    }

    ll result = static_cast<ll>(x);

    if (result * result < n) {
        result++;
    }

    cout << result << endl;

    return 0;
}