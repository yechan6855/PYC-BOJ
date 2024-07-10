#include <bits/stdc++.h>
#define ll long long
#define io ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct SegTree {
    ll tree[1 << 18];
    ll lazy[1 << 18];
    ll sz = 1 << 17;
    void construct() {
        for (ll i = sz - 1; i > 0; i--) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }
    void propagate(ll node, ll nodeL, ll nodeR) {
        if (lazy[node]) {
            if (node < sz) {
                lazy[node << 1] += lazy[node];
                lazy[node << 1 | 1] += lazy[node];
            }
            tree[node] += lazy[node] * (nodeR - nodeL + 1);
            lazy[node] = 0;
        }
    }
    void update(ll L, ll R, ll k, ll node, ll nodeL, ll nodeR) {
        propagate(node, nodeL, nodeR);
        if (R < nodeL || nodeR < L) return;
        if (L <= nodeL && nodeR <= R) {
            lazy[node] += k;
            propagate(node, nodeL, nodeR);
            return;
        }
        ll mid = nodeL + nodeR >> 1;
        update(L, R, k, node << 1, nodeL, mid);
        update(L, R, k, node << 1 | 1, mid + 1, nodeR);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }
    void update(ll l, ll r, ll k) {
        update(l, r, k, 1, 1, sz);
    }
    ll query(ll L, ll R, ll node, ll nodeL, ll nodeR) {
        propagate(node, nodeL, nodeR);
        if (R < nodeL || nodeR < L) return 0;
        if (L <= nodeL && nodeR <= R) return tree[node];
        ll mid = nodeL + nodeR >> 1;
        return query(L, R, node << 1, nodeL, mid) + query(L, R, node << 1 | 1, mid + 1, nodeR);
    }
    ll query(ll l, ll r) {
        return query(l, r, 1, 1, sz);
    }
} s;

int main() {
    io;
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i++){
        cin >> v[i];
    }
    for (ll i = 1; i <= n; i++) {
        s.tree[s.sz - 1 + i] = v[i] - v[i - 1];
    }
    s.construct();
    ll q;
    cin >> q;
    while (q--) {
        ll t, a, b; cin >> t;
        if (--t) {
            cin >> a;
            cout << s.query(1, a) << '\n';
        }
        else {
            cin >> a >> b;
            s.update(a, b, 1);
            s.update(b + 1, b + 1, -(b - a + 1));
        }
    }
}