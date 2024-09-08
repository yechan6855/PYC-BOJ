#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int depth[100001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    depth[start] = 0;

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int next : graph[current]) {
            if(depth[next] == -1) {
                q.push(next);
                depth[next] = depth[current] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    fill(depth, depth + N + 1, -1);

    bfs(R);

    for(int i = 1; i <= N; i++) {
        cout << depth[i] << '\n';
    }

    return 0;
}