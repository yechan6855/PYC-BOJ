#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define endl "\n"
using namespace std;

class LazySegmentTree {
private:
    vector<int> tree, lazy;
    int size;

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            if ((end - start + 1) % 2 != 0) {
                tree[node] ^= lazy[node];
            }
            if (start != end) {
                lazy[node * 2] ^= lazy[node];
                lazy[node * 2 + 1] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int value) {
        propagate(node, start, end);
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] ^= value;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, value);
        updateRange(node * 2 + 1, mid + 1, end, l, r, value);
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }

    int queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return queryRange(node * 2, start, mid, l, r) ^ queryRange(node * 2 + 1, mid + 1, end, l, r);
    }

public:
    LazySegmentTree(int n) {
        size = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, node * 2, start, mid);
            build(arr, node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
        }
    }

    void update(int l, int r, int value) {
        updateRange(1, 0, size - 1, l, r, value);
    }

    int query(int l, int r) {
        return queryRange(1, 0, size - 1, l, r);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    LazySegmentTree segTree(N);
    segTree.build(A, 1, 0, N - 1);

    int M;
    cin >> M;
    while (M--) {
        int type, i, j, k;
        cin >> type >> i >> j;
        if (type == 1) {
            cin >> k;
            segTree.update(i, j, k);
        } else if (type == 2) {
            cout << segTree.query(i, j) << endl;
        }
    }

    return 0;
}