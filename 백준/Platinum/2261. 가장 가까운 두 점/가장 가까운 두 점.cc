#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define pi pair<int, int>

using namespace std;

vector<pi> point;

int getDist(pi a, pi b) {
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}

int solve(int left, int right) {
    if (left == right) {
        return INT_MAX;
    } else {
        int mid = (left + right) / 2;
        int min_dist = min(solve(left, mid), solve(mid + 1, right));
        vector<pi> target_list;

        for (int i = mid; i >= left; --i) {
            if ((point[i].fi - point[mid].fi) * (point[i].fi - point[mid].fi) < min_dist) {
                target_list.pb(point[i]);
            } else {
                break;
            }
        }

        for (int j = mid + 1; j <= right; ++j) {
            if ((point[j].fi - point[mid].fi) * (point[j].fi - point[mid].fi) < min_dist) {
                target_list.pb(point[j]);
            } else {
                break;
            }
        }

        sort(target_list.begin(), target_list.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.se < b.se;
        });

        for (size_t i = 0; i < target_list.size() - 1; ++i) {
            for (size_t j = i + 1; j < target_list.size(); ++j) {
                if ((target_list[i].se - target_list[j].se) * (target_list[i].se - target_list[j].se) < min_dist) {
                    int dist = getDist(target_list[i], target_list[j]);
                    min_dist = min(min_dist, dist);
                } else {
                    break;
                }
            }
        }
        return min_dist;
    }
}

int main() {
    io;

    int N;
    cin >> N;
    point.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> point[i].fi >> point[i].se;
    }

    sort(point.begin(), point.end());

    set<pi> point_set(point.begin(), point.end());
    if (point.size() != point_set.size()) {
        cout << 0 << endl;
    } else {
        cout << solve(0, point.size() - 1) << endl;
    }

    return 0;
}