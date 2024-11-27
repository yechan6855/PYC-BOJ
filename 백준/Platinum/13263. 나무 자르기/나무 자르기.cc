#include <bits/stdc++.h>
#define ll long long
#define Line pair<ll, ll>
using namespace std;

struct ConvexHullTrick {
    vector<Line> hull;

    double getInter(const Line& a, const Line& b) {
        return (double)(a.second - b.second) / (double)(b.first - a.first);
    }

    void insertion(ll m, ll c) {
        Line newLine = {m, c};
        hull.emplace_back(newLine);

        while (hull.size() >= 3) {
            int n = hull.size();
            Line l1 = hull[n-3];
            Line l2 = hull[n-2];
            Line l3 = hull[n-1];

            double x1 = getInter(l1, l2);
            double x2 = getInter(l2, l3);

            if (x1 >= x2) {
                hull.erase(hull.begin() + n - 2);
            }
            else {
                break;
            }
        }
    }

    ll query(ll x) {
        int low = 0;
        int high = hull.size() - 1;
        int best = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid < hull.size() - 1) {
                ll y1 = hull[mid].first * x + hull[mid].second;
                ll y2 = hull[mid + 1].first * x + hull[mid + 1].second;
                if (y1 <= y2) {
                    high = mid - 1;
                    best = mid;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                best = mid;
                break;
            }
        }

        return hull[best].first * x + hull[best].second;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    vector<ll> b(n);
    for(int i=0; i<n; ++i){
        cin >> b[i];
    }

    vector<ll> dp(n, 0);
    dp[0] = 0;

    ConvexHullTrick cht;
    cht.insertion(b[0], dp[0]);

    for(int i=1; i<n; ++i){
        dp[i] = cht.query(a[i]);
        cht.insertion(b[i], dp[i]);
    }

    cout << dp[n-1];
}