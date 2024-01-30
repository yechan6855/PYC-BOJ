#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100000;

int visited[MAX + 1];

int bfs(int start, int target) {
    memset(visited, -1, sizeof(visited));
    queue<int> q;

    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 순간이동
        if (current * 2 <= MAX && visited[current * 2] == -1) {
            visited[current * 2] = visited[current];
            q.push(current * 2);
        }

        // 걷기 (뒤로 가는 경우도 확인)
        for (int next : {current - 1, current + 1}) {
            if (next >= 0 && next <= MAX && visited[next] == -1) {
                visited[next] = visited[current] + 1;
                q.push(next);
            }
        }
    }

    return visited[target];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int result = bfs(N, K);

    cout << result << '\n';

    return 0;
}