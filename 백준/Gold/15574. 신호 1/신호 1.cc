#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int,int>
#define mp map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct Signal {
    int x, y;
};

double dist(const Signal& a, const Signal& b) {
    return sqrt((ll)(b.x - a.x) * (b.x - a.x) + (ll)(b.y - a.y) * (b.y - a.y));
}

int main() {
    io
    int N;
    cin >> N;
    vector<Signal> signals(N);
    for (int i = 0; i < N; ++i) {
        cin >> signals[i].x >> signals[i].y;
    }

    sort(signals.begin(), signals.end(), [](const Signal& a, const Signal& b) {
        return a.x < b.x;
    });

    vector<double> dp(N, 0.0);
    double max_dist = 0.0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (signals[i].x > signals[j].x) {
                dp[i] = max(dp[i], dp[j] + dist(signals[j], signals[i]));
            }
        }
        max_dist = max(max_dist, dp[i]);
    }

    cout << fixed << setprecision(7) << max_dist << endl;

    return 0;
}