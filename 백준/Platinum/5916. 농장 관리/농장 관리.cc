#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAXN = 100000;

struct SegmentTree {
    int n;
    vi tree, lazy;

    SegmentTree(int size) : n(size) {
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update_range(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end);
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update_range(node * 2, start, mid, l, r, val);
        update_range(node * 2 + 1, mid + 1, end, l, r, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query_range(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query_range(node * 2, start, mid, l, r) + query_range(node * 2 + 1, mid + 1, end, l, r);
    }

    void update(int l, int r, int val) {
        update_range(1, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return query_range(1, 0, n - 1, l, r);
    }
};

struct HLD {
    int n, cur_pos;
    vi parent, depth, heavy, head, pos, subtree_size;
    SegmentTree seg_tree;

    HLD(int size) : n(size), seg_tree(size), cur_pos(0) {
        parent.resize(n);
        depth.resize(n);
        heavy.resize(n, -1);
        head.resize(n);
        pos.resize(n);
        subtree_size.resize(n);
    }

    int dfs(const vvi& adj, int v) {
        int size = 1, max_c_size = 0;
        for (int c : adj[v]) {
            if (c != parent[v]) {
                parent[c] = v;
                depth[c] = depth[v] + 1;
                int c_size = dfs(adj, c);
                size += c_size;
                if (c_size > max_c_size) {
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }

    void decompose(const vvi& adj, int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1) {
            decompose(adj, heavy[v], h);
        }
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v]) {
                decompose(adj, c, c);
            }
        }
    }

    void init(const vvi& adj) {
        dfs(adj, 0);
        decompose(adj, 0, 0);
    }

    void update_path(int u, int v, int val) {
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            seg_tree.update(pos[head[v]], pos[v], val);
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        seg_tree.update(pos[u] + 1, pos[v], val);
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res += seg_tree.query(pos[head[v]], pos[v]);
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res += seg_tree.query(pos[u] + 1, pos[v]);
        return res;
    }
};

int32_t main() {
    io;
    int n, m;
    cin >> n >> m;

    vvi adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    HLD hld(n);
    hld.init(adj);

    for (int i = 0; i < m; ++i) {
        char type;
        int u, v;
        cin >> type >> u >> v;
        --u; --v;
        if (type == 'P') {
            hld.update_path(u, v, 1);
        } else if (type == 'Q') {
            cout << hld.query_path(u, v) << endl;
        }
    }

    return 0;
}