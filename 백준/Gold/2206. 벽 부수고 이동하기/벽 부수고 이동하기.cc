#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int MAX = 1000;
const int INF = 1e9;

int N, M;
int maze[MAX][MAX];
int visited[MAX][MAX][2];  // 벽을 부순 상태에 따른 방문 여부

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 1));  // 시작점 (0, 0)에서 시작하며 벽을 아직 부수지 않았음을 나타냄
    visited[0][0][1] = 1;

    while (!q.empty()) {
        int x, y, can_break;
        tie(x, y, can_break) = q.front();
        q.pop();

        if (x == N - 1 && y == M - 1) {
            return visited[x][y][can_break];
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (maze[nx][ny] == 0 && visited[nx][ny][can_break] == 0) {
                    visited[nx][ny][can_break] = visited[x][y][can_break] + 1;
                    q.push(make_tuple(nx, ny, can_break));
                } else if (maze[nx][ny] == 1 && can_break == 1 && visited[nx][ny][0] == 0) {
                    visited[nx][ny][0] = visited[x][y][can_break] + 1;
                    q.push(make_tuple(nx, ny, 0));
                }
            }
        }
    }

    return -1;  // 목적지에 도달할 수 없는 경우
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%1d", &maze[i][j]);
        }
    }

    int result = bfs();

    if (result == -1) {
        cout << "-1" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}