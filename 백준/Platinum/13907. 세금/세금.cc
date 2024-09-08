#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_N = 1000;

int N, M, K, S, D;
vector<vector<pair<int, int>>> graph;
vector<int> tax_increases;
vector<vector<int>> dist;

void dijkstra() {
    dist.assign(N + 1, vector<int>(N + 1, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    dist[S][0] = 0;
    pq.push({0, S, 0});

    while (!pq.empty()) {
        auto [cost, cur, edges] = pq.top();
        pq.pop();

        if (cost > dist[cur][edges]) continue;
        if (edges >= N) continue;

        for (auto &[next, w] : graph[cur]) {
            int next_cost = cost + w;
            if (next_cost < dist[next][edges + 1]) {
                dist[next][edges + 1] = next_cost;
                pq.push({next_cost, next, edges + 1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K >> S >> D;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    for (int i = 0; i < K; i++) {
        int tax;
        cin >> tax;
        tax_increases.push_back(tax);
    }

    dijkstra();

    int cur_tax = 0;
    for (int i = 0; i <= K; i++) {
        int min_cost = INF;
        for (int j = 1; j <= N; j++) {
            if (dist[D][j] != INF) {
                min_cost = min(min_cost, dist[D][j] + j * cur_tax);
            }
        }
        cout << min_cost << "\n";

        if (i < K) {
            cur_tax += tax_increases[i];
        }
    }

    return 0;
}