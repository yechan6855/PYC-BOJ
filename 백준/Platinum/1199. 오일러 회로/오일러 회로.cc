#include <bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAX = 1001;
vector<map<int, int>> graph;
vector<int> circuit;
int N;

void dfs(int v) {
    while (!graph[v].empty()) {
        int u = graph[v].begin()->first;
        if (--graph[v][u] == 0) graph[v].erase(u);
        if (--graph[u][v] == 0) graph[u].erase(v);
        dfs(u);
    }
    circuit.push_back(v);
}

int main() {
    io;
    cin >> N;
    graph.resize(N);

    ll tot = 0;
    for (int i = 0; i < N; i++) {
        int degree = 0;
        for (int j = 0; j < N; j++) {
            int edges;
            cin >> edges;
            if (edges > 0) {
                graph[i][j] = edges;
                degree += edges;
            }
        }
        tot += degree;
        if (degree % 2 != 0) {
            cout << -1;
            return 0;
        }
    }

    if (tot == 0) {
        cout << "1\n1";
        return 0;
    }

    dfs(0);

    if (circuit.size() != tot / 2 + 1) {
        cout << -1;
        return 0;
    }

    for (int i = circuit.size() - 1; i >= 0; i--) {
        cout << circuit[i] + 1 << ' ';
    }

    return 0;
}