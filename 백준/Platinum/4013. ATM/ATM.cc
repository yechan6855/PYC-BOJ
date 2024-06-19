#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

const int MAXN = 500000;
vi graph[MAXN + 1];
vi rgraph[MAXN + 1];
vi scc_graph[MAXN + 1];
int atm[MAXN + 1];
bool restaurant[MAXN + 1];
bool visited[MAXN + 1];
stack<int> stk;
int scc_id[MAXN + 1];
int scc_atm[MAXN + 1];
bool scc_restaurant[MAXN + 1];
vi sccs[MAXN + 1];
int dp[MAXN + 1];

void dfs1(int node) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next])
            dfs1(next);
    }
    stk.push(node);
}

void dfs2(int node, int id) {
    visited[node] = true;
    scc_id[node] = id;
    scc_atm[id] += atm[node];
    scc_restaurant[id] |= restaurant[node];
    sccs[id].push_back(node);
    for (int next : rgraph[node]) {
        if (!visited[next])
            dfs2(next, id);
    }
}

int main() {
    io;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        rgraph[v].pb(u);
    }

    for (int i = 1; i <= N; ++i) {
        cin >> atm[i];
    }

    int S, P;
    cin >> S >> P;

    memset(restaurant, false, sizeof(restaurant));
    for (int i = 0; i < P; ++i) {
        int r;
        cin >> r;
        restaurant[r] = true;
    }

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= N; ++i) {
        if (!visited[i])
            dfs1(i);
    }

    memset(visited, false, sizeof(visited));
    int scc_count = 0;
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if (!visited[node])
            dfs2(node, scc_count++);
    }

    for (int i = 0; i < scc_count; ++i) {
        for (int u : sccs[i]) {
            for (int v : graph[u]) {
                if (scc_id[u] != scc_id[v]) {
                    scc_graph[scc_id[u]].pb(scc_id[v]);
                }
            }
        }
    }

    memset(dp, 0, sizeof(dp));
    qi q;
    q.push(scc_id[S]);
    dp[scc_id[S]] = scc_atm[scc_id[S]];

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : scc_graph[u]) {
            if (dp[v] < dp[u] + scc_atm[v]) {
                dp[v] = dp[u] + scc_atm[v];
                q.push(v);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < scc_count; ++i) {
        if (scc_restaurant[i])
            result = max(result, dp[i]);
    }

    cout << result << endl;

    return 0;
}