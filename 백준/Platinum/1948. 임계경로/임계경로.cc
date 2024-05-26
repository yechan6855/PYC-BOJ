#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX = 10001;

vector<pair<int, int>> adj[MAX];
vector<pair<int, int>> reverse_adj[MAX];
int indegree[MAX];
int dist[MAX];
bool visited[MAX];
int n, m;

void topological_sort(int start, vector<int>& topo_order) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        topo_order.push_back(cur);

        for (auto &edge : adj[cur]) {
            int next = edge.first;
            if (--indegree[next] == 0) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        reverse_adj[v].emplace_back(u, w);
        indegree[v]++;
    }

    int start, end;
    cin >> start >> end;

    vector<int> topo_order;
    topological_sort(start, topo_order);

    memset(dist, 0, sizeof(dist));

    for (int i = 0; i < topo_order.size(); i++) {
        int cur = topo_order[i];
        for (auto &edge : adj[cur]) {
            int next = edge.first;
            int weight = edge.second;
            if (dist[next] < dist[cur] + weight) {
                dist[next] = dist[cur] + weight;
            }
        }
    }

    cout << dist[end] << endl;

    queue<int> q;
    q.push(end);
    memset(visited, false, sizeof(visited));
    visited[end] = true;

    int count = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &edge : reverse_adj[cur]) {
            int prev = edge.first;
            int weight = edge.second;
            if (dist[cur] == dist[prev] + weight) {
                count++;
                if (!visited[prev]) {
                    q.push(prev);
                    visited[prev] = true;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}