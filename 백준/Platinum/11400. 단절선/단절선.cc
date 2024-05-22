#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define fi first
#define se second
using namespace std;

vector<int> adj[100001];
vector<pair<int, int>> bridges;
int visited[100001], low[100001];
int timer;

void dfs(int v, int p = -1) {
    visited[v] = low[v] = ++timer;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], visited[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > visited[v]) {
                bridges.push_back({min(v, to), max(v, to)});
            }
        }
    }
}

int32_t main() {
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    for (int i = 1; i <= V; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    sort(bridges.begin(), bridges.end());

    cout << bridges.size() << endl;
    for (auto &bridge : bridges) {
        cout << bridge.fi << " " << bridge.se << endl;
    }

    return 0;
}