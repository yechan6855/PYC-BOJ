#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, cost;
    Edge(int _to, int _cost) : to(_to), cost(_cost) {}
};

void dijkstra(int start, vector<int>& items, vector<vector<Edge>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (cost > dist[current]) continue;

        for (const Edge& edge : graph[current]) {
            int next = edge.to;
            int nextCost = cost + edge.cost;

            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> items(n + 1);
    vector<vector<Edge>> graph(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> items[i];
    }

    for (int i = 0; i < r; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].emplace_back(b, l);
        graph[b].emplace_back(a, l);
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> dist(n + 1, INF);
        dijkstra(i, items, graph, dist);

        int total = 0;
        for (int j = 1; j <= n; ++j) {
            if (dist[j] <= m) {
                total += items[j];
            }
        }
        result = max(result, total);
    }
    cout << result << endl;

    return 0;
}