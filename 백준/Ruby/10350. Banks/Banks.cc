#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll solve(double x) {
    if (x == (ll)x) return (ll)x;
    return (x > 0) ? (ll)x + 1 : (ll)x;
}

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> s(n * 2 + 1, 0);
    for (int i = 0; i < 2 * n; ++i) {
        s[i + 1] = s[i] + a[i % n];
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[j + i] < s[j - 1]) {
                ans += solve(abs(s[j + i] - s[j - 1]) / (double)s[n]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}