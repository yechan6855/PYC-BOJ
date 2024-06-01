#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 1, 0, n - 1);
    }

    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }

    int query(int k) {
        return query(1, 0, n - 1, k);
    }

private:
    vector<int> tree;
    int n;

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node, start, mid);
            build(data, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] += value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, value);
            } else {
                update(2 * node + 1, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int k) {
        if (start == end) {
            return start;
        }
        int mid = (start + end) / 2;
        if (tree[2 * node] >= k) {
            return query(2 * node, start, mid, k);
        } else {
            return query(2 * node + 1, mid + 1, end, k - tree[2 * node]);
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> troops(N);

    for (int i = 0; i < N; ++i) {
        cin >> troops[i];
    }

    SegmentTree segTree(troops);

    cin >> M;

    while (M--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, a;
            cin >> i >> a;
            segTree.update(i - 1, a);
        } else if (type == 2) {
            int i;
            cin >> i;
            cout << segTree.query(i) + 1 << endl;
        }
    }

    return 0;
}