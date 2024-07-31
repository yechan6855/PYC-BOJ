#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

const int MAX = 801;
const int INF = 1e9;

int N, P;
int capacity[MAX][MAX], flow[MAX][MAX];
vector<int> graph[MAX];

int networkFlow(int source, int sink) {
    int totalFlow = 0;
    while (true) {
        vector<int> parent(MAX, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);

        while (!q.empty() && parent[sink] == -1) {
            int here = q.front(); q.pop();
            for (int there : graph[here]) {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }

        if (parent[sink] == -1) break;

        int amount = INF;
        for (int p = sink; p != source; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }

        for (int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }

        totalFlow += amount;
    }
    return totalFlow;
}

int main() {
    io;
    cin >> N >> P;

    for (int i = 1; i <= N; i++) {
        int in = i, out = i + N;
        graph[in].push_back(out);
        graph[out].push_back(in);
        capacity[in][out] = 1;
    }

    for (int i = 0; i < P; i++) {
        int u, v;
        cin >> u >> v;
        graph[u + N].push_back(v);
        graph[v].push_back(u + N);
        capacity[u + N][v] = 1;
        graph[v + N].push_back(u);
        graph[u].push_back(v + N);
        capacity[v + N][u] = 1;
    }

    cout << networkFlow(1 + N, 2) << '\n';

    return 0;
}