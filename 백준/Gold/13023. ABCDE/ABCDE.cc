#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

bool dfs(int node, int depth) {
    if (depth == 4) {
        return true;  // 조건을 만족하는 경로를 찾았음
    }

    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, depth + 1)) {
                return true;  // 깊이 우선 탐색을 통해 조건을 만족하는 경로를 찾았음
            }
        }
    }

    visited[node] = false;  // 백트래킹

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool found = false;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, 0)) {
                found = true;
                break;
            }
        }
    }
    cout << (found ? 1 : 0) << endl;

    return 0;
}