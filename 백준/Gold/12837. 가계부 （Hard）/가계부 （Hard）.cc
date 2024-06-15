#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define MOD 9901
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

class SegmentTree {
private:
    vector<ll> tree;
    vector<ll> lazy;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int l, int r, ll val) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end or start > r or end < l)
            return;

        if (start >= l and end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    ll query(int node, int start, int end, int l, int r) {
        if (start > end or start > r or end < l)
            return 0;

        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start >= l and end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        ll p1 = query(2 * node, start, mid, l, r);
        ll p2 = query(2 * node + 1, mid + 1, end, l, r);
        return (p1 + p2);
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(1, 1, n);
    }

    void update(int l, int r, ll val) {
        update(1, 1, n, l, r, val);
    }

    ll query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

int main() {
    io;
    int N, Q;
    cin >> N >> Q;
    SegmentTree segTree(N);

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int p;
            ll x;
            cin >> p >> x;
            segTree.update(p, p, x);
        } else if (type == 2) {
            int p, q;
            cin >> p >> q;
            cout << segTree.query(p, q) << endl;
        }
    }

    return 0;
}