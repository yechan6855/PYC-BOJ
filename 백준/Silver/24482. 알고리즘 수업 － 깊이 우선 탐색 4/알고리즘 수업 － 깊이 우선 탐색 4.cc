#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> depth;
int order = 0;

void dfs(int node, int d) {
    depth[node] = d;

    for (int next : graph[node]) {
        if (depth[next] == -1) {
            dfs(next, d + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    graph.resize(N + 1);
    depth.resize(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    dfs(R, 0);

    for (int i = 1; i <= N; i++) {
        cout << depth[i] << '\n';
    }

    return 0;
}