#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAXN = 1000;
const int INF = 1e9;

int N, W;
pair<int, int> events[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];
int path[MAXN + 1][MAXN + 1];

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int p1, int p2, int event_idx) {
    if (event_idx > W) {
        return 0;
    }

    int &res = dp[p1][p2];
    if (res != -1) {
        return res;
    }

    int next_event = event_idx;
    pair<int, int> p1_pos = (p1 == 0) ? make_pair(1, 1) : events[p1];
    pair<int, int> p2_pos = (p2 == 0) ? make_pair(N, N) : events[p2];

    int move_p1 = solve(next_event, p2, event_idx + 1) + dist(p1_pos, events[next_event]);
    int move_p2 = solve(p1, next_event, event_idx + 1) + dist(p2_pos, events[next_event]);

    if (move_p1 < move_p2) {
        res = move_p1;
        path[p1][p2] = 1;
    } else {
        res = move_p2;
        path[p1][p2] = 2;
    }

    return res;
}

void reconstruct_path(int p1, int p2, int event_idx) {
    if (event_idx > W) {
        return;
    }

    int next_event = event_idx;
    if (path[p1][p2] == 1) {
        cout << "1\n";
        reconstruct_path(next_event, p2, event_idx + 1);
    } else {
        cout << "2\n";
        reconstruct_path(p1, next_event, event_idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> W;

    for (int i = 1; i <= W; ++i) {
        cin >> events[i].first >> events[i].second;
    }

    memset(dp, -1, sizeof(dp));
    memset(path, -1, sizeof(path));

    cout << solve(0, 0, 1) << endl;
    reconstruct_path(0, 0, 1);

    return 0;
}