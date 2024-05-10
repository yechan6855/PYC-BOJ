#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int INF = 1e9 * 3001LL;

struct SegmentTree {
    vector<array<int, 4>> tree;
    int CAP;

    SegmentTree(int cap) {
        CAP = 1 << static_cast<int>(log2(cap) + 1);
        tree.resize(CAP << 1, {-INF, -INF, -INF, 0});
    }

    void update(int idx, int value) {
        int i = CAP + idx;
        int new_val = tree[i][3] + value;
        tree[i] = {new_val, new_val, new_val, new_val};

        for (i >>= 1; i > 0; i >>= 1) {
            auto &A = tree[i << 1], &B = tree[(i << 1) | 1];
            tree[i] = {
                    max(A[0], A[3] + B[0]),
                    max(B[1], B[3] + A[1]),
                    max({A[2], B[2], A[1] + B[0]}),
                    A[3] + B[3]
            };
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<tuple<int, int, int>> points(N);
    set<int> x_set, y_set;

    for (int i = 0; i < N; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        points[i] = {x, y, w};
        x_set.insert(x);
        y_set.insert(y);
    }

    map<int, int> x_map, y_map;
    int idx = 0;
    for (int x : x_set) x_map[x] = idx++;
    idx = 0;
    for (int y : y_set) y_map[y] = idx++;

    int X = x_map.size(), Y = y_map.size();
    vector<vector<pair<int, int>>> y_data(Y), x_data(X);

    for (auto &[x, y, w] : points) {
        y_data[y_map[y]].emplace_back(x_map[x], w);
        x_data[x_map[x]].emplace_back(y_map[y], w);
    }

    int ans = 0;
    if (Y <= X) {
        for (int sy = 0; sy < Y; ++sy) {
            SegmentTree st(X);
            for (int ey = sy; ey < Y; ++ey) {
                for (auto &[x, w] : y_data[ey]) {
                    st.update(x, w);
                }
                ans = max(ans, st.tree[1][2]);
            }
        }
    } else {
        for (int sx = 0; sx < X; ++sx) {
            SegmentTree st(Y);
            for (int ex = sx; ex < X; ++ex) {
                for (auto &[y, w] : x_data[ex]) {
                    st.update(y, w);
                }
                ans = max(ans, st.tree[1][2]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}