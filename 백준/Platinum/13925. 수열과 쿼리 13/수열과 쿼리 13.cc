#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MOD 1000000007
using namespace std;

struct SegmentTree {
    int n;
    vector<ll> tree, lazy_add, lazy_mul, lazy_set;
    vector<bool> is_set;

    SegmentTree(const vector<ll> &data) {
        n = data.size();
        tree.resize(4 * n);
        lazy_add.resize(4 * n, 0);
        lazy_mul.resize(4 * n, 1);
        lazy_set.resize(4 * n, 0);
        is_set.resize(4 * n, false);
        build(0, 0, n - 1, data);
    }

    void build(int node, int start, int end, const vector<ll> &data) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid, data);
            build(2 * node + 2, mid + 1, end, data);
            tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MOD;
        }
    }

    void update_add(int node, int start, int end, int l, int r, ll val) {
        propagate(node, start, end);
        if (start > end || start > r || end < l)
            return;
        if (start >= l && end <= r) {
            lazy_add[node] = (lazy_add[node] + val) % MOD;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update_add(2 * node + 1, start, mid, l, r, val);
        update_add(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MOD;
    }

    void update_mul(int node, int start, int end, int l, int r, ll val) {
        propagate(node, start, end);
        if (start > end || start > r || end < l)
            return;
        if (start >= l && end <= r) {
            lazy_mul[node] = (lazy_mul[node] * val) % MOD;
            lazy_add[node] = (lazy_add[node] * val) % MOD;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update_mul(2 * node + 1, start, mid, l, r, val);
        update_mul(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MOD;
    }

    void update_set(int node, int start, int end, int l, int r, ll val) {
        propagate(node, start, end);
        if (start > end || start > r || end < l)
            return;
        if (start >= l && end <= r) {
            is_set[node] = true;
            lazy_set[node] = val;
            lazy_mul[node] = 1;
            lazy_add[node] = 0;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update_set(2 * node + 1, start, mid, l, r, val);
        update_set(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MOD;
    }

    ll query(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (start > end || start > r || end < l)
            return 0;
        if (start >= l && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        ll p1 = query(2 * node + 1, start, mid, l, r);
        ll p2 = query(2 * node + 2, mid + 1, end, l, r);
        return (p1 + p2) % MOD;
    }

    void propagate(int node, int start, int end) {
        if (is_set[node]) {
            tree[node] = (lazy_set[node] * (end - start + 1)) % MOD;
            if (start != end) {
                is_set[2 * node + 1] = true;
                is_set[2 * node + 2] = true;
                lazy_set[2 * node + 1] = lazy_set[node];
                lazy_set[2 * node + 2] = lazy_set[node];
                lazy_mul[2 * node + 1] = 1;
                lazy_mul[2 * node + 2] = 1;
                lazy_add[2 * node + 1] = 0;
                lazy_add[2 * node + 2] = 0;
            }
            is_set[node] = false;
        }
        if (lazy_mul[node] != 1) {
            tree[node] = (tree[node] * lazy_mul[node]) % MOD;
            if (start != end) {
                lazy_mul[2 * node + 1] = (lazy_mul[2 * node + 1] * lazy_mul[node]) % MOD;
                lazy_mul[2 * node + 2] = (lazy_mul[2 * node + 2] * lazy_mul[node]) % MOD;
                lazy_add[2 * node + 1] = (lazy_add[2 * node + 1] * lazy_mul[node]) % MOD;
                lazy_add[2 * node + 2] = (lazy_add[2 * node + 2] * lazy_mul[node]) % MOD;
            }
            lazy_mul[node] = 1;
        }
        if (lazy_add[node] != 0) {
            tree[node] = (tree[node] + lazy_add[node] * (end - start + 1)) % MOD;
            if (start != end) {
                lazy_add[2 * node + 1] = (lazy_add[2 * node + 1] + lazy_add[node]) % MOD;
                lazy_add[2 * node + 2] = (lazy_add[2 * node + 2] + lazy_add[node]) % MOD;
            }
            lazy_add[node] = 0;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    SegmentTree seg(A);
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int type, x, y;
        ll v;
        cin >> type >> x >> y;
        x--; y--;
        if (type == 1) {
            cin >> v;
            seg.update_add(0, 0, N - 1, x, y, v);
        } else if (type == 2) {
            cin >> v;
            seg.update_mul(0, 0, N - 1, x, y, v);
        } else if (type == 3) {
            cin >> v;
            seg.update_set(0, 0, N - 1, x, y, v);
        } else if (type == 4) {
            cout << seg.query(0, 0, N - 1, x, y) << endl;
        }
    }
    return 0;
}