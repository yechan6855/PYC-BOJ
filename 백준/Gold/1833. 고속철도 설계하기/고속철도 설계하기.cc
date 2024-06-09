#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define di deque<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

int find(vi& parent, int u) {
    if (parent[u] != u) {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

void unite(vi& parent, vi& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int main() {
    io;
    int N;
    cin >> N;

    vector<Edge> edges;
    vector<Edge> existingEdges;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cost;
            cin >> cost;
            if (i < j) {
                if (cost < 0) {
                    existingEdges.pb({i + 1, j + 1, -cost});
                } else {
                    edges.pb({i + 1, j + 1, cost});
                }
            }
        }
    }

    sort(edges.begin(), edges.end());

    vi parent(N + 1);
    vi rank(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    vector<Edge> result;

    for (const auto& edge : existingEdges) {
        unite(parent, rank, edge.u, edge.v);
        totalCost += edge.cost;
    }

    for (const auto& edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            unite(parent, rank, edge.u, edge.v);
            totalCost += edge.cost;
            result.pb(edge);
        }
    }

    cout << totalCost << " " << result.size() << endl;
    for (const auto& edge : result) {
        cout << edge.u << " " << edge.v << endl;
    }

    return 0;
}