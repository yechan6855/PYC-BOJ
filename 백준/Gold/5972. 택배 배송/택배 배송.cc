#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<int> dijkstra(int N, vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < cost) continue;

        for (auto& edge : graph[curr]) {
            int next = edge.first;
            int nextCost = cost + edge.second;

            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    vector<int> result = dijkstra(N, graph, 1);

    cout << result[N] << '\n';

    return 0;
}