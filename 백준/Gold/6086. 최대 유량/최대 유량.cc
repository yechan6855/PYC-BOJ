#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX = 52;
const int INF = 1e9;

int capacity[MAX][MAX], flow[MAX][MAX];
vector<int> graph[MAX];

int charToInt(char c) {
    if (c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int maximumFlow(int source, int sink) {
    int totalFlow = 0;

    while (true) {
        vector<int> parent(MAX, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[sink] == -1) {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur]) {
                if (parent[next] == -1 && capacity[cur][next] - flow[cur][next] > 0) {
                    q.push(next);
                    parent[next] = cur;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        int from = charToInt(u);
        int to = charToInt(v);
        capacity[from][to] += w;
        capacity[to][from] += w;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    cout << maximumFlow(charToInt('A'), charToInt('Z')) << endl;

    return 0;
}