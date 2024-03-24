#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
int N, M;
vector<int> graph[MAX];
int depth[MAX];
int parent[MAX][17];

void dfs(int node, int d) {
    depth[node] = d;
    for (int next : graph[node]) {
        if (depth[next] == -1) {
            parent[next][0] = node;
            dfs(next, d + 1);
        }
    }
}

void setParent() {
    dfs(1, 0);
    for (int j = 1; j <= 16; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);

    for (int i = 16; i >= 0; i--) {
        if (depth[b] - depth[a] >= (1 << i))
            b = parent[b][i];
    }

    if (a == b) return a;

    for (int i = 16; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    fill(depth, depth + N + 1, -1);
    setParent();

    cin >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}