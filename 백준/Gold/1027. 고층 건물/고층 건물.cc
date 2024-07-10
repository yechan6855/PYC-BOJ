#include <bits/stdc++.h>
#define int double
#define x first
#define y second
#define endl "\n"
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define io ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int ccw(pii a, pii b, pii c) {
    return (a.x * b.y + b.x * c.y + c.x * a.y) -
           (a.y * b.x + b.y * c.x + c.y * a.x);
}

void solve() {
    int N;
    cin >> N;
    if (N < 3) {
        cout << N - 1 << endl;
        return;
    }

    vi H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        vi res;

        if (i > 0) {
            res.pb(i - 1);
            for (int j = i - 2; j >= 0; --j) {
                if (ccw({i, H[i]}, {res.back(), H[res.back()]}, {j, H[j]}) < 0) {
                    res.pb(j);
                }
            }
        }

        if (i < N - 1) {
            res.pb(i + 1);
            for (int j = i + 2; j < N; ++j) {
                if (ccw({i, H[i]}, {res.back(), H[res.back()]}, {j, H[j]}) > 0) {
                    res.pb(j);
                }
            }
        }

        ans = max(ans, (int)res.size());
    }

    cout << ans << endl;
}

int32_t main() {
    io;
    solve();
}