#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int snakeAndLadder[101];
    memset(snakeAndLadder, 0, sizeof(snakeAndLadder));

    bool isVisited[101];
    memset(isVisited, false, sizeof(isVisited));

    int count[101];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < N + M; ++i) {
        int u, v;
        cin >> u >> v;
        snakeAndLadder[u] = v;
    }

    queue<int> q;
    q.push(1);
    count[1] = 0;
    isVisited[1] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == 100) {
            cout << count[now] << endl;
            break;
        }

        for (int i = 1; i <= 6; ++i) {
            int next = now + i;

            if (next > 100 || isVisited[next])  continue;

            if (snakeAndLadder[next] != 0) {
                if (!isVisited[snakeAndLadder[next]]) {
                    isVisited[snakeAndLadder[next]] = true;
                    count[snakeAndLadder[next]] = count[now] + 1;
                    q.push(snakeAndLadder[next]);
                }
            } else {
                isVisited[next] = true;
                count[next] = count[now] + 1;
                q.push(next);
            }
        }
    }
    return 0;
}