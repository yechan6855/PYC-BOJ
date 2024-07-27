#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define di deque<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

struct Pt {
    int x, y, i;
    Pt(int x = 0, int y = 0, int i = 0) : x(x), y(y), i(i) {}
};

ll ccw(const Pt& a, const Pt& b, const Pt& c) {
    return 1LL * (a.x * b.y + b.x * c.y + c.x * a.y) - 1LL * (a.y * b.x + b.y * c.x + c.y * a.x);
}

void solve() {
    int n;
    cin >> n;
    vector<Pt> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
        pts[i].i = i;
    }

    sort(pts.begin(), pts.end(), [](const Pt& a, const Pt& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    vector<bool> u(n, false);
    vector<Pt> hull;
    for (const auto& p : pts) {
        while (hull.size() > 1) {
            if (ccw(hull[hull.size() - 2], hull.back(), p) >= 0)
                break;
            u[hull.back().i] = false;
            hull.pob();
        }
        hull.pb(p);
        u[p.i] = true;
    }

    vi ans;
    for (const auto& p : pts) {
        if (!u[p.i]) {
            ans.pb(p.i);
        }
    }

    for (int i = hull.size() - 1; i >= 0; i--) {
        ans.pb(hull[i].i);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? endl : " ");
    }
}

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}