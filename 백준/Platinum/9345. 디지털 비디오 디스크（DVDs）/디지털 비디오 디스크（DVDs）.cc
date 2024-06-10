#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define MAX INT_MAX
#define MIN INT_MIN
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct SegmentTree {
    int n;
    vi tree_min, tree_max;

    SegmentTree(int size) {
        n = size;
        tree_min.resize(4 * n);
        tree_max.resize(4 * n);
    }

    void build(int node, int start, int end, const vi &data) {
        if (start == end) {
            tree_min[node] = data[start];
            tree_max[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid, data);
            build(2 * node + 2, mid + 1, end, data);
            tree_min[node] = min(tree_min[2 * node + 1], tree_min[2 * node + 2]);
            tree_max[node] = max(tree_max[2 * node + 1], tree_max[2 * node + 2]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree_min[node] = value;
            tree_max[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree_min[node] = min(tree_min[2 * node + 1], tree_min[2 * node + 2]);
            tree_max[node] = max(tree_max[2 * node + 1], tree_max[2 * node + 2]);
        }
    }

    pi query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) {
            return {MAX, MIN};
        }
        if (L <= start && end <= R) {
            return {tree_min[node], tree_max[node]};
        }
        int mid = (start + end) / 2;
        auto left = query(2 * node + 1, start, mid, L, R);
        auto right = query(2 * node + 2, mid + 1, end, L, R);
        return {min(left.fi, right.fi), max(left.se, right.se)};
    }
};

int main() {
    io;
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vi data(N);
        for (int i = 0; i < N; ++i) {
            data[i] = i;
        }

        SegmentTree seg_tree(N);
        seg_tree.build(0, 0, N - 1, data);

        for (int i = 0; i < K; ++i) {
            int Q, A, B;
            cin >> Q >> A >> B;

            if (Q == 0) {
                int val_a = data[A];
                int val_b = data[B];
                data[A] = val_b;
                data[B] = val_a;
                seg_tree.update(0, 0, N - 1, A, val_b);
                seg_tree.update(0, 0, N - 1, B, val_a);
            } else if (Q == 1) {
                auto result = seg_tree.query(0, 0, N - 1, A, B);
                if (result.fi == A && result.se == B) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}