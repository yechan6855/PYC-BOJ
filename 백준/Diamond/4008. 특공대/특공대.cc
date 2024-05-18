#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
struct Line {
    ll slope, intercept;
    Line(ll s, ll i) : slope(s), intercept(i) {}
    ll value(ll x) const {
        return slope * x + intercept;
    }
};

bool isBad(const Line &line1, const Line &line2, const Line &line3) {
    return (line1.intercept - line2.intercept) * (line3.slope - line2.slope) >= (line2.intercept - line3.intercept) * (line2.slope - line1.slope);
}

void addLine(deque<Line> &hull, ll slope, ll intercept) {
    Line newLine(slope, intercept);
    while (hull.size() >= 2 && isBad(hull[hull.size() - 2], hull.back(), newLine)) {
        hull.pop_back();
    }
    hull.push_back(newLine);
}

ll query(deque<Line> &hull, ll x) {
    while (hull.size() >= 2 && hull[0].value(x) <= hull[1].value(x)) {
        hull.pop_front();
    }
    return hull.front().value(x);
}

ll t(double x) {
    return (x >= 0) ? static_cast<ll>(floor(x)) : static_cast<ll>(ceil(x));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll a, b, c;
    cin >> n >> a >> b >> c;
    vector<ll> x(n + 1);
    vector<ll> sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        sum[i] = sum[i - 1] + x[i];
    }

    vector<ll> dp(n + 1, 0);
    deque<Line> hull;
    hull.emplace_back(0, 0);

    for (int i = 1; i <= n; ++i) {
        dp[i] = a * sum[i] * sum[i] + b * sum[i] + c + query(hull, sum[i]);
        addLine(hull, -2 * a * sum[i], dp[i] + a * sum[i] * sum[i] - b * sum[i]);
    }

    cout << dp[n] << endl;

    return 0;
}