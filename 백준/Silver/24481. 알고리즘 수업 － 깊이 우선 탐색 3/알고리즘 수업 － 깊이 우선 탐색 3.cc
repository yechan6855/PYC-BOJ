#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> depth;
int N, M, R;

void dfs(int node, int current_depth) {
    depth[node] = current_depth;

    for (int next : graph[node]) {
        if (depth[next] == -1) {
            dfs(next, current_depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;

    graph.resize(N + 1);
    depth.assign(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(R, 0);

    for (int i = 1; i <= N; i++) {
        cout << depth[i] << '\n';
    }

    return 0;
}