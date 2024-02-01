#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

vector<int> parent;

int findParent(int node) {
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node]);
}

void unionSets(int u, int v) {
    int rootU = findParent(u);
    int rootV = findParent(v);

    if (rootU != rootV)
        parent[rootU] = rootV;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);

    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    sort(edges.begin(), edges.end());

    parent.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    int totalCost = 0;
    int maxEdgeCost = 0;

    for (const Edge& edge : edges) {
        if (findParent(edge.u) != findParent(edge.v)) {
            unionSets(edge.u, edge.v);
            totalCost += edge.cost;
            maxEdgeCost = max(maxEdgeCost, edge.cost);
        }
    }
    // 최소 스패닝 트리의 총 비용에서 가장 큰 간선의 비용을 뺀 값이 답
    cout << totalCost - maxEdgeCost << '\n';

    return 0;
}