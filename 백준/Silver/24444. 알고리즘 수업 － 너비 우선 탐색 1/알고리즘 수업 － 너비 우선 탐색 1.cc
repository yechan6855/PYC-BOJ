#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int visited[100001] = {0,};
int order[100001] = {0,};
int cnt = 1;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    order[start] = cnt++;

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];
            if(visited[next] == 0) {
                q.push(next);
                visited[next] = 1;
                order[next] = cnt++;
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

    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(R);

    for(int i = 1; i <= N; i++) {
        cout << order[i] << '\n';
    }

    return 0;
}