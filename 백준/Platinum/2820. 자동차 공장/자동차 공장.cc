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
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAXN = 500001;

ll N, M;
ll salary[MAXN];
ll start[MAXN], finish[MAXN], euler[MAXN * 2];
ll timer = 1;
vvi tree(MAXN);

struct SegmentTree {
    ll tree[4 * MAXN];
    ll lazy[4 * MAXN];

    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = salary[euler[start]];
        } else {
            ll mid = (start + end) / 2;
            build(node * 2, start, mid);
            build(node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void propagate(ll node, ll start, ll end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(ll node, ll start, ll end, ll l, ll r, ll val) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[node * 2] += val;
                lazy[node * 2 + 1] += val;
            }
            return;
        }
        ll mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid + 1, end, l, r, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    ll query(ll node, ll start, ll end, ll pos) {
        propagate(node, start, end);
        if (start == end) return tree[node];
        ll mid = (start + end) / 2;
        if (pos <= mid) return query(node * 2, start, mid, pos);
        else return query(node * 2 + 1, mid + 1, end, pos);
    }
};

SegmentTree segTree;

void dfs(ll node) {
    start[node] = timer;
    euler[timer++] = node;
    for (ll v : tree[node]) {
        dfs(v);
    }
    finish[node] = timer - 1;
}

int main() {
    io;
    cin >> N >> M;
    cin >> salary[1];
    for (ll i = 2; i <= N; i++) {
        ll s;
        cin >> salary[i] >> s;
        tree[s].pb(i);
    }

    dfs(1);
    segTree.build(1, 1, N);

    while (M--) {
        char type;
        ll a, x;
        cin >> type;
        if (type == 'p') {
            cin >> a >> x;
            segTree.update(1, 1, N, start[a] + 1, finish[a], x);
        } else if (type == 'u') {
            cin >> a;
            cout << segTree.query(1, 1, N, start[a]) << endl;
        }
    }

    return 0;
}