#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < cost) continue;

        for (const auto& edge : graph[current]) {
            int next = edge.first;
            int nextCost = cost + edge.second;

            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    dist.assign(N + 1, INF);

    for (int i = 0; i < M; ++i) {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start].push_back({end, cost});
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start);

    cout << dist[end] << endl;

    return 0;
}