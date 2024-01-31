#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int dx[] = {0, 0, -1, 1}; // 상하좌우 방향
int dy[] = {-1, 1, 0, 0};

struct State {
    int rx, ry, bx, by, depth;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    queue<State> q;
    vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(m, false))));

    int rx, ry, bx, by;
    // 초기 위치 찾기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
            } else if (board[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }

    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;

    while (!q.empty()) {
        int curRx = q.front().rx;
        int curRy = q.front().ry;
        int curBx = q.front().bx;
        int curBy = q.front().by;
        int curDepth = q.front().depth;

        q.pop();

        // 10번 이상 움직이면 실패로 간주
        if (curDepth >= 10) {
            cout << "-1\n";
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nextRx = curRx, nextRy = curRy;
            int nextBx = curBx, nextBy = curBy;

            // 빨간 구슬 이동
            while (true) {
                nextRx += dx[i];
                nextRy += dy[i];

                if (board[nextRx][nextRy] == '#') {
                    nextRx -= dx[i];
                    nextRy -= dy[i];
                    break;
                }

                if (board[nextRx][nextRy] == 'O') {
                    break;
                }
            }

            // 파란 구슬 이동
            while (true) {
                nextBx += dx[i];
                nextBy += dy[i];

                if (board[nextBx][nextBy] == '#') {
                    nextBx -= dx[i];
                    nextBy -= dy[i];
                    break;
                }

                if (board[nextBx][nextBy] == 'O') {
                    break;
                }
            }

            // 파란 구슬이 구멍에 빠지면 실패
            if (board[nextBx][nextBy] == 'O') {
                continue;
            }

            // 빨간 구슬만 구멍에 빠지면 성공
            if (board[nextRx][nextRy] == 'O') {
                cout << curDepth + 1 << "\n";
                return 0;
            }

            // 빨간 구슬과 파란 구슬의 위치가 같다면 위치 조정
            if (nextRx == nextBx && nextRy == nextBy) {
                int distRed = abs(nextRx - curRx) + abs(nextRy - curRy);
                int distBlue = abs(nextBx - curBx) + abs(nextBy - curBy);

                if (distRed > distBlue) {
                    nextRx -= dx[i];
                    nextRy -= dy[i];
                } else {
                    nextBx -= dx[i];
                    nextBy -= dy[i];
                }
            }

            // 방문하지 않은 상태라면 큐에 삽입
            if (!visited[nextRx][nextRy][nextBx][nextBy]) {
                visited[nextRx][nextRy][nextBx][nextBy] = true;
                q.push({nextRx, nextRy, nextBx, nextBy, curDepth + 1});
            }
        }
    }
    // 10번 이내에 구멍에 빠지지 않으면 실패
    cout << "-1\n";

    return 0;
}