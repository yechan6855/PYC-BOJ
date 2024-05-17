#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

class SegmentTree {
private:
    vector<int> tree, lazy;
    int size;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            tree[node] ^= lazy[node] * ((end - start + 1) % 2);
            if (start != end) {
                lazy[2 * node] ^= lazy[node];
                lazy[2 * node + 1] ^= lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end or start > r or end < l) return;

        if (start >= l and end <= r) {
            tree[node] ^= val * ((end - start + 1) % 2);
            if (start != end) {
                lazy[2 * node] ^= val;
                lazy[2 * node + 1] ^= val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int queryRange(int node, int start, int end, int idx) {
        if (start > end or start > idx or end < idx) return 0;

        if (lazy[node] != 0) {
            tree[node] ^= lazy[node] * ((end - start + 1) % 2);
            if (start != end) {
                lazy[2 * node] ^= lazy[node];
                lazy[2 * node + 1] ^= lazy[node];
            }
            lazy[node] = 0;
        }

        if (start == end) return tree[node];

        int mid = (start + end) / 2;
        if (idx <= mid)
            return queryRange(2 * node, start, mid, idx);
        else
            return queryRange(2 * node + 1, mid + 1, end, idx);
    }

public:
    SegmentTree(vector<int>& arr) {
        size = arr.size();
        tree.resize(4 * size, 0);
        lazy.resize(4 * size, 0);
        build(arr, 1, 0, size - 1);
    }

    void updateRange(int l, int r, int val) {
        updateRange(1, 0, size - 1, l, r, val);
    }

    int queryRange(int idx) {
        return queryRange(1, 0, size - 1, idx);
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

    SegmentTree segTree(arr);

    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            segTree.updateRange(a, b, c);
        } else if (t == 2) {
            int a;
            cin >> a;
            cout << segTree.queryRange(a) << endl;
        }
    }

    return 0;
}