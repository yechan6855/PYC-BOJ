#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

class LazySegmentTree {
public:
    LazySegmentTree(int n) : n(n) {
        data.resize(4 * n);
        lazy.resize(4 * n);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            data[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            data[node] = data[2 * node] + data[2 * node + 1];
        }
    }

    void updateRange(int l, int r, int value) {
        updateRange(1, 0, n - 1, l, r, value);
    }

    int query(int idx) {
        return query(1, 0, n - 1, idx);
    }

private:
    int n;
    vector<int> data, lazy;

    void updateRange(int node, int start, int end, int l, int r, int value) {
        if (lazy[node] != 0) {
            data[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l) {
            return;
        }

        if (start >= l && end <= r) {
            data[node] += (end - start + 1) * value;
            if (start != end) {
                lazy[2 * node] += value;
                lazy[2 * node + 1] += value;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, value);
        updateRange(2 * node + 1, mid + 1, end, l, r, value);
        data[node] = data[2 * node] + data[2 * node + 1];
    }

    int query(int node, int start, int end, int idx) {
        if (lazy[node] != 0) {
            data[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start == end) {
            return data[node];
        }

        int mid = (start + end) / 2;
        if (idx <= mid) {
            return query(2 * node, start, mid, idx);
        } else {
            return query(2 * node + 1, mid + 1, end, idx);
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    LazySegmentTree segTree(n);
    segTree.build(arr, 1, 0, n - 1);

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            segTree.updateRange(l - 1, r - 1, k);
        } else if (type == 2) {
            int x;
            cin >> x;
            cout << segTree.query(x - 1) << endl;
        }
    }

    return 0;
}