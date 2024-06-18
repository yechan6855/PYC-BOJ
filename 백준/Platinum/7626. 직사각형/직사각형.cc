#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

struct Event {
    int x, y1, y2, type;
    bool operator<(const Event& other) const {
        return x < other.x;
    }
};

class SegmentTree {
public:
    SegmentTree(int n) : count(4 * n), length(4 * n), compressed_y(n) {}

    void update(int node, int start, int end, int y1, int y2, int value) {
        if (start >= y2 || end <= y1) return;
        if (start >= y1 && end <= y2) {
            count[node] += value;
        } else {
            int mid = (start + end) / 2;
            update(node * 2, start, mid, y1, y2, value);
            update(node * 2 + 1, mid, end, y1, y2, value);
        }
        if (count[node] > 0) {
            length[node] = compressed_y[end] - compressed_y[start];
        } else {
            length[node] = (start + 1 == end) ? 0 : length[node * 2] + length[node * 2 + 1];
        }
    }

    vi count, length, compressed_y;
};

int main() {
    io;
    int N;
    cin >> N;
    vector<Event> events;
    vi y_coords;

    for (int i = 0; i < N; ++i) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        events.pb({x1, y1, y2, 1});
        events.pb({x2, y1, y2, -1});
        y_coords.pb(y1);
        y_coords.pb(y2);
    }

    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    mi y_compress;
    for (int i = 0; i < y_coords.size(); ++i) {
        y_compress[y_coords[i]] = i;
    }

    SegmentTree seg_tree(y_coords.size());
    for (int i = 0; i < y_coords.size(); ++i) {
        seg_tree.compressed_y[i] = y_coords[i];
    }

    sort(events.begin(), events.end());

    ll total_area = 0;
    int prev_x = events[0].x;

    for (const auto& event : events) {
        int cur_x = event.x;
        int y1 = y_compress[event.y1];
        int y2 = y_compress[event.y2];

        total_area += (ll)(cur_x - prev_x) * seg_tree.length[1];
        seg_tree.update(1, 0, y_coords.size() - 1, y1, y2, event.type);

        prev_x = cur_x;
    }

    cout << total_area << endl;
    return 0;
}