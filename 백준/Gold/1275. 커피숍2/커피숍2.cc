#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int size;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, L, R);
        int right = query(2 * node + 1, mid + 1, end, L, R);
        return left + right;
    }

public:
    SegmentTree(vector<int>& arr) {
        size = arr.size() - 1;
        tree.resize(4 * size);
        build(arr, 1, 1, size);
    }

    void update(int idx, int val) {
        update(1, 1, size, idx, val);
    }

    int query(int L, int R) {
        if (L > R) swap(L, R);
        return query(1, 1, size, L, R);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    SegmentTree segmentTree(A);

    for (int q = 0; q < Q; ++q) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << segmentTree.query(x, y) << endl;
        segmentTree.update(a, b);
    }

    return 0;
}