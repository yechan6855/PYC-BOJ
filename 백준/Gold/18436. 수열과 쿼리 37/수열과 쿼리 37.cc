#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define endl "\n"
#define elif else if
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct SegmentTree {
    int size;
    vector<pi> tree;

    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, {0, 0});
    }

    void build(const vi& arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size()) {
                if (arr[lx] % 2 == 0) {
                    tree[x] = {1, 0};
                } else {
                    tree[x] = {0, 1};
                }
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, mid);
        build(arr, 2 * x + 2, mid, rx);
        tree[x] = {
                tree[2 * x + 1].fi + tree[2 * x + 2].fi,
                tree[2 * x + 1].se + tree[2 * x + 2].se
        };
    }

    void build(const vi& arr) {
        build(arr, 0, 0, size);
    }

    void update(int i, int val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (val % 2 == 0) {
                tree[x] = {1, 0};
            } else {
                tree[x] = {0, 1};
            }
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            update(i, val, 2 * x + 1, lx, mid);
        } else {
            update(i, val, 2 * x + 2, mid, rx);
        }
        tree[x] = {
                tree[2 * x + 1].fi + tree[2 * x + 2].fi,
                tree[2 * x + 1].se + tree[2 * x + 2].se
        };
    }

    void update(int i, int val) {
        update(i, val, 0, 0, size);
    }

    pi query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return {0, 0};
        if (lx >= l && rx <= r) return tree[x];
        int mid = (lx + rx) / 2;
        auto left = query(l, r, 2 * x + 1, lx, mid);
        auto right = query(l, r, 2 * x + 2, mid, rx);
        return {
                left.fi + right.fi,
                left.se + right.se
        };
    }

    pi query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    io;
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    SegmentTree st(n);
    st.build(arr);

    int m;
    cin >> m;
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x;
            --i;
            st.update(i, x);
        } elif (type == 2) {
            int l, r;
            cin >> l >> r;
            --l;
            auto res = st.query(l, r);
            cout << res.fi << endl;
        } elif (type == 3) {
            int l, r;
            cin >> l >> r;
            --l;
            auto res = st.query(l, r);
            cout << res.se << endl;
        }
    }

    return 0;
}