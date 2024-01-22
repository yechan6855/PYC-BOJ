// BFS

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000;

int box[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Point {
    int x, y, day;
};

int main() {
    int m, n;
    cin >> m >> n;

    queue<Point> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({i, j, 0});
                visited[i][j] = 1;
            }
        }
    }

    int maxDay = 0;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        maxDay = max(maxDay, cur.day);

        for (int k = 0; k < 4; ++k) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && box[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({nx, ny, cur.day + 1});
                box[nx][ny] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (box[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << maxDay << "\n";
    return 0;
}