#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;
vector<int> graph[MAX];
bool visited[MAX];
int order[MAX];
int cnt = 1;

void dfs(int x) {
    visited[x] = true;
    order[x] = cnt++;

    for (int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << order[i] << '\n';
    }

    return 0;
}