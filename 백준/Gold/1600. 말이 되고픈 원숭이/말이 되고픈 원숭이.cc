#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200;
const int INF = 987654321;

int K, W, H;
int board[MAX][MAX];
bool visited[MAX][MAX][31]; // 31은 말의 움직임을 사용한 횟수

// 말의 움직임
int horse_dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int horse_dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

// 일반적인 이동
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Point {
    int x, y, k, move;
};

int bfs() {
    queue<Point> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int k = q.front().k;
        int move = q.front().move;
        q.pop();

        if (x == H - 1 && y == W - 1) {
            return move;
        }

        // 일반적인 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny][k] && board[nx][ny] != 1) {
                visited[nx][ny][k] = true;
                q.push({nx, ny, k, move + 1});
            }
        }

        // 말의 이동 (말의 이동을 사용할 수 있을 때)
        if (k < K) {
            for (int i = 0; i < 8; i++) {
                int nx = x + horse_dx[i];
                int ny = y + horse_dy[i];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny][k + 1] && board[nx][ny] != 1) {
                    visited[nx][ny][k + 1] = true;
                    q.push({nx, ny, k + 1, move + 1});
                }
            }
        }
    }

    return -1; // 도착할 수 없는 경우
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }
    int result = bfs();

    cout << result << "\n";

    return 0;
}