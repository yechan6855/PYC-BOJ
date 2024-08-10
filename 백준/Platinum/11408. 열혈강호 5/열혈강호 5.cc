#include <bits/stdc++.h>
using namespace std;

const int MAX = 805;
const int INF = 1e9;

int N, M;
vector<int> graph[MAX];
int capacity[MAX][MAX], flow[MAX][MAX], cost[MAX][MAX];
int parent[MAX], dist[MAX];
bool inQueue[MAX];

void addEdge(int from, int to, int cap, int cst) {
    graph[from].push_back(to);
    graph[to].push_back(from);
    capacity[from][to] = cap;
    cost[from][to] = cst;
    cost[to][from] = -cst;
}

bool SPFA(int start, int end) {
    fill(dist, dist + MAX, INF);
    fill(inQueue, inQueue + MAX, false);
    fill(parent, parent + MAX, -1);

    queue<int> q;
    q.push(start);
    dist[start] = 0;
    inQueue[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        inQueue[cur] = false;

        for (int next : graph[cur]) {
            if (capacity[cur][next] - flow[cur][next] > 0 &&
                dist[next] > dist[cur] + cost[cur][next]) {
                dist[next] = dist[cur] + cost[cur][next];
                parent[next] = cur;
                if (!inQueue[next]) {
                    q.push(next);
                    inQueue[next] = true;
                }
            }
        }
    }

    return dist[end] != INF;
}

pair<int, int> MCMF(int start, int end) {
    int totalFlow = 0, totalCost = 0;

    while (SPFA(start, end)) {
        int curFlow = INF;
        for (int i = end; i != start; i = parent[i]) {
            curFlow = min(curFlow, capacity[parent[i]][i] - flow[parent[i]][i]);
        }

        for (int i = end; i != start; i = parent[i]) {
            totalCost += curFlow * cost[parent[i]][i];
            flow[parent[i]][i] += curFlow;
            flow[i][parent[i]] -= curFlow;
        }

        totalFlow += curFlow;
    }

    return {totalFlow, totalCost};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    int start = 0, end = N + M + 1;

    for (int i = 1; i <= N; i++) {
        addEdge(start, i, 1, 0);
        int workCount;
        cin >> workCount;
        while (workCount--) {
            int j, c;
            cin >> j >> c;
            addEdge(i, N + j, 1, c);
        }
    }

    for (int j = 1; j <= M; j++) {
        addEdge(N + j, end, 1, 0);
    }

    pair<int, int> result = MCMF(start, end);

    cout << result.first << '\n' << result.second << '\n';

    return 0;
}