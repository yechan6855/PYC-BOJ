#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 100001;

vector<int> graph[MAX];
ll visited[MAX], depth[MAX];
int order = 1;

void DevSe(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = order++;
    depth[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (visited[next] == 0) {
                visited[next] = order++;
                depth[next] = depth[current] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DevSe(R);

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += visited[i] * depth[i];
    }

    cout << ans << '\n';

    return 0;
}