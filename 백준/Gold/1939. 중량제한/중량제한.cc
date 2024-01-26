// 이분 탐색 + BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> adj[10001]; // 각 섬에서 연결된 다리 정보 (다리의 도착지와 중량)

bool bfs(int start, int end, int weight, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (const auto& edge : adj[current]) {
            int next = edge.first;
            int nextWeight = edge.second;

            if (!visited[next] && nextWeight >= weight) {
                visited[next] = true;
                q.push(next);

                if (next == end) {
                    return true; // 도착지에 도달 가능
                }
            }
        }
    }

    return false; // 도착지에 도달할 수 없음
}

int main() {
    int n, m;
    cin >> n >> m;

    int maxWeight = 0;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        maxWeight = max(maxWeight, c);
    }

    int start, end;
    cin >> start >> end;

    int left = 1;
    int right = maxWeight;
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (bfs(start, end, mid, n)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result << endl;

    return 0;
}