#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

class TwoSAT {
private:
    int n;
    vector<vector<int>> graph, reverse_graph;
    vector<int> component, order;
    vector<bool> visited;
    int component_count;

    void addImplication(int x, int y) {
        graph[x].push_back(y);
        reverse_graph[y].push_back(x);
    }

    int neg(int x) {
        return x ^ 1;
    }

    void dfs1(int node) {
        visited[node] = true;
        for (int next : graph[node]) {
            if (!visited[next])
                dfs1(next);
        }
        order.push_back(node);
    }

    void dfs2(int node, int label) {
        component[node] = label;
        for (int next : reverse_graph[node]) {
            if (component[next] == -1)
                dfs2(next, label);
        }
    }

public:
    TwoSAT(int variables) : n(2 * variables) {
        graph.resize(n);
        reverse_graph.resize(n);
        visited.assign(n, false);
        component.assign(n, -1);
    }

    void addClause(int x, int y) {
        if (x < 0) x = (-x - 1) * 2 + 1;
        else x = (x - 1) * 2;

        if (y < 0) y = (-y - 1) * 2 + 1;
        else y = (y - 1) * 2;

        addImplication(neg(x), y);
        addImplication(neg(y), x);
    }

    bool isSatisfiable() {
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) dfs1(i);
        }

        reverse(order.begin(), order.end());
        component_count = 0;

        for (int node : order) {
            if (component[node] == -1)
                dfs2(node, component_count++);
        }

        for (int i = 0; i < n; i += 2) {
            if (component[i] == component[neg(i)])
                return false;
        }
        return true;
    }
};

int32_t main() {
    int N, M;
    cin >> N >> M;

    TwoSAT solver(N);

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        solver.addClause(x, y);
    }

    if (solver.isSatisfiable()) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}