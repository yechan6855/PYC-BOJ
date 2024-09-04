#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int INF = numeric_limits<int>::max();

int bfs(int N, int start, int T, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(N + 1, INF);
    queue<int> q;
    int escaped = 0;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (dist[current] <= T) {
            escaped++;
        }

        for (const auto& neighbor : graph[current]) {
            int next = neighbor.first;
            int weight = neighbor.second;

            if (dist[current] + weight < dist[next] && dist[current] + weight <= T) {
                dist[next] = dist[current] + weight;
                q.push(next);
            }
        }
    }

    return escaped;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E, T, M;
    cin >> N >> E >> T >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int A, B, time;
        cin >> A >> B >> time;
        graph[B].push_back({A, time});
    }

    int ans = bfs(N, E, T, graph);

    cout << ans << endl;

    return 0;
}