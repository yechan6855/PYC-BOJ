#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Edge {
    int start;
    int end;
    int cost;
};

vector<int> parent;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

bool compareEdge(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> x(N);
    vector<pair<int, int>> y(N);
    vector<pair<int, int>> z(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i].first >> y[i].first >> z[i].first;
        x[i].second = y[i].second = z[i].second = i;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    vector<Edge> edges;
    for (int i = 0; i < N - 1; i++) {
        edges.push_back({x[i].second, x[i + 1].second, abs(x[i].first - x[i + 1].first)});
        edges.push_back({y[i].second, y[i + 1].second, abs(y[i].first - y[i + 1].first)});
        edges.push_back({z[i].second, z[i + 1].second, abs(z[i].first - z[i + 1].first)});
    }

    sort(edges.begin(), edges.end(), compareEdge);

    parent.resize(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    for (const auto& edge : edges) {
        if (find(edge.start) != find(edge.end)) {
            totalCost += edge.cost;
            unionSet(edge.start, edge.end);
        }
    }
    cout << totalCost << endl;

    return 0;
}