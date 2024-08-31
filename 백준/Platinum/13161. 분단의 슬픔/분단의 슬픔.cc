#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 502;
const int INF = 1e9;

int N, source, sink;
int capacity[MAX_N][MAX_N], flow[MAX_N][MAX_N];
vector<int> graph[MAX_N];
int level[MAX_N], work[MAX_N];

bool bfs() {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(source);
    level[source] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (level[next] == -1 && capacity[cur][next] - flow[cur][next] > 0) {
                level[next] = level[cur] + 1;
                q.push(next);
            }
        }
    }

    return level[sink] != -1;
}

int dfs(int cur, int amount) {
    if (cur == sink) return amount;

    for (int &i = work[cur]; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (level[next] == level[cur] + 1 && capacity[cur][next] - flow[cur][next] > 0) {
            int df = dfs(next, min(amount, capacity[cur][next] - flow[cur][next]));
            if (df > 0) {
                flow[cur][next] += df;
                flow[next][cur] -= df;
                return df;
            }
        }
    }

    return 0;
}

int dinic() {
    int max_flow = 0;
    while (bfs()) {
        memset(work, 0, sizeof(work));
        while (int df = dfs(source, INF)) {
            max_flow += df;
        }
    }
    return max_flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    source = 0, sink = N + 1;

    vector<int> group(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> group[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int w;
            cin >> w;
            if (i < j) {
                graph[i].push_back(j);
                graph[j].push_back(i);
                capacity[i][j] = capacity[j][i] = w;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (group[i] == 1) {
            graph[source].push_back(i);
            graph[i].push_back(source);
            capacity[source][i] = INF;
        } else if (group[i] == 2) {
            graph[i].push_back(sink);
            graph[sink].push_back(i);
            capacity[i][sink] = INF;
        }
    }

    int max_flow = dinic();

    vector<bool> visited(N + 2, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (!visited[next] && capacity[cur][next] - flow[cur][next] > 0) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    cout << max_flow << '\n';

    for (int i = 1; i <= N; i++) {
        if (visited[i]) cout << i << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) cout << i << ' ';
    }
    cout << '\n';

    return 0;
}