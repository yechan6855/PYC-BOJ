#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
vector<int> adj[MAXN];
int dp[MAXN][2];
bool visited[MAXN];

void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = 1;
    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child);
            dp[node][0] += dp[child][1];
            dp[node][1] += min(dp[child][0], dp[child][1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, 0, sizeof(visited));
    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}