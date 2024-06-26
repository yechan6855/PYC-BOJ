#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

const int MAXN = 100000;
const int LOG = 17;

struct Edge {
    int to, weight;
};

int N, M;
vector<Edge> adj[MAXN + 1];
int depth[MAXN + 1];
int parent[MAXN + 1][LOG];
long long dist[MAXN + 1];

void dfs(int v, int p, int d, long long w) {
    depth[v] = d;
    parent[v][0] = p;
    dist[v] = w;
    for (int i = 1; i < LOG; ++i) {
        if (parent[v][i-1] != -1) {
            parent[v][i] = parent[parent[v][i-1]][i-1];
        } else {
            parent[v][i] = -1;
        }
    }
    for (Edge e : adj[v]) {
        if (e.to != p) {
            dfs(e.to, v, d + 1, w + e.weight);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i) {
        if ((diff >> i) & 1) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int get_kth_ancestor(int u, int k) {
    for (int i = 0; i < LOG; ++i) {
        if ((k >> i) & 1) {
            u = parent[u][i];
        }
    }
    return u;
}

int32_t main() {
    io;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    fill(parent[0], parent[0] + MAXN * LOG, -1);

    dfs(1, -1, 0, 0);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int q;
        cin >> q;
        if (q == 1) {
            int u, v;
            cin >> u >> v;
            int l = lca(u, v);
            cout << dist[u] + dist[v] - 2 * dist[l] << endl;
        } else if (q == 2) {
            int u, v, k;
            cin >> u >> v >> k;
            int l = lca(u, v);
            int total_steps = depth[u] + depth[v] - 2 * depth[l] + 1;
            if (k <= depth[u] - depth[l] + 1) {
                cout << get_kth_ancestor(u, k - 1) << endl;
            } else {
                k = total_steps - k;
                cout << get_kth_ancestor(v, k) << endl;
            }
        }
    }

    return 0;
}