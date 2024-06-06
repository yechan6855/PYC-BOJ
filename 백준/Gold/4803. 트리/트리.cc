#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define as assign
#define pi pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

vvi adj;
vector<bool> visited;

bool bfs(int start) {
    qi q;
    q.push(start);
    visited[start] = true;
    int edges = 0, nodes = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        nodes++;

        for (int neighbor : adj[node]) {
            edges++;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return edges == 2 * (nodes - 1);
}

int32_t main() {
    io;
    int caseNum = 1;

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        adj.as(n + 1, vi());
        visited.as(n + 1, false);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int treeCount = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (bfs(i)) {
                    treeCount++;
                }
            }
        }

        cout << "Case " << caseNum << ": ";
        if (treeCount == 0) {
            cout << "No trees." << endl;
        } else if (treeCount == 1) {
            cout << "There is one tree." << endl;
        } else {
            cout << "A forest of " << treeCount << " trees." << endl;
        }

        caseNum++;
    }

    return 0;
}