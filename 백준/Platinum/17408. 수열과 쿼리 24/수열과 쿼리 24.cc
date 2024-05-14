#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int INF = 1e9;
const int MAXN = 100000;

struct Node {
    long long max1, max2;
};

class SegmentTree {
private:
    vector<Node> tree;
    int size;

    Node combine(Node left, Node right) {
        vector<long long> values = {left.max1, left.max2, right.max1, right.max2};
        sort(values.rbegin(), values.rend());
        return {values[0], values[1]};
    }

    void build(vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start], -INF};
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = {val, -INF};
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    Node query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return {-INF, -INF};
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node left = query(2 * node, start, mid, L, R);
        Node right = query(2 * node + 1, mid + 1, end, L, R);
        return combine(left, right);
    }

public:
    SegmentTree(vector<long long>& arr) {
        size = arr.size() - 1;
        tree.resize(4 * size);
        build(arr, 1, 1, size);
    }

    void update(int idx, long long val) {
        update(1, 1, size, idx, val);
    }

    long long query(int L, int R) {
        Node res = query(1, 1, size, L, R);
        return res.max1 + res.max2;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    SegmentTree segmentTree(A);

    cin >> M;

    for (int q = 0; q < M; ++q) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            long long v;
            cin >> i >> v;
            segmentTree.update(i, v);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << segmentTree.query(l, r) << endl;
        }
    }

    return 0;
}