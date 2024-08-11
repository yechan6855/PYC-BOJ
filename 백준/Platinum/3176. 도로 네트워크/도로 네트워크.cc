#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
const int LOG = 17;

int n, m;
vector<pair<int, int>> graph[MAX];
int parent[MAX][LOG];
int depth[MAX];
int minDist[MAX][LOG];
int maxDist[MAX][LOG];

void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node][0] = par;

    for (auto &p : graph[node]) {
        int next = p.first;
        int dist = p.second;
        if (next != par) {
            minDist[next][0] = maxDist[next][0] = dist;
            dfs(next, node, d + 1);
        }
    }
}

void buildTable() {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j-1] != -1) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
                minDist[i][j] = min(minDist[i][j-1], minDist[parent[i][j-1]][j-1]);
                maxDist[i][j] = max(maxDist[i][j-1], maxDist[parent[i][j-1]][j-1]);
            }
        }
    }
}

pair<int, int> query(int u, int v) {
    int minResult = 1e9, maxResult = 0;

    if (depth[u] < depth[v]) swap(u, v);

    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - depth[v] >= (1 << i)) {
            minResult = min(minResult, minDist[u][i]);
            maxResult = max(maxResult, maxDist[u][i]);
            u = parent[u][i];
        }
    }

    if (u == v) return {minResult, maxResult};

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            minResult = min({minResult, minDist[u][i], minDist[v][i]});
            maxResult = max({maxResult, maxDist[u][i], maxDist[v][i]});
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    minResult = min({minResult, minDist[u][0], minDist[v][0]});
    maxResult = max({maxResult, maxDist[u][0], maxDist[v][0]});

    return {minResult, maxResult};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill(&parent[0][0], &parent[MAX-1][LOG], -1);
    fill(&minDist[0][0], &minDist[MAX-1][LOG], 1e9);
    fill(&maxDist[0][0], &maxDist[MAX-1][LOG], 0);

    dfs(1, -1, 0);
    buildTable();

    cin >> m;
    while (m--) {
        int d, e;
        cin >> d >> e;
        auto result = query(d, e);
        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}