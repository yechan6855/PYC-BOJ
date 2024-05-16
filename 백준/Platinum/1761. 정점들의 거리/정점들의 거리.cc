#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int MAXN = 40000;
const int LOG = 16;

vector<pair<int, int>> adj[MAXN + 1];
int depth[MAXN + 1];
int parent[MAXN + 1][LOG];
int dist[MAXN + 1];

void dfs(int v, int p, int d) {
    depth[v] = d;
    for (auto &edge : adj[v]) {
        int u = edge.first, w = edge.second;
        if (u != p) {
            dist[u] = dist[v] + w;
            parent[u][0] = v;
            dfs(u, v, d + 1);
        }
    }
}

void preprocess(int N) {
    memset(parent, -1, sizeof(parent));
    dfs(1, -1, 0);

    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= N; ++i) {
            if (parent[i][j-1] != -1) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; diff; ++i) {
        if (diff & 1) {
            u = parent[u][i];
        }
        diff >>= 1;
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    preprocess(N);

    int M;
    cin >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        int ancestor = lca(u, v);
        int distance = dist[u] + dist[v] - 2 * dist[ancestor];
        cout << distance << endl;
    }

    return 0;
}