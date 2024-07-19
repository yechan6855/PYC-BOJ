#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
    io;
    int n, m;
    cin >> m >> n;

    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            maze[i][j] = line[j] - '0';
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push(make_tuple(0, 0, 0));

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!pq.empty()) {
        int walls, x, y;
        tie(walls, x, y) = pq.top();
        pq.pop();

        if (x == n - 1 && y == m - 1) {
            cout << walls << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int new_walls = walls + maze[nx][ny];

                if (new_walls < dist[nx][ny]) {
                    dist[nx][ny] = new_walls;
                    pq.push(make_tuple(new_walls, nx, ny));
                }
            }
        }
    }

    return 0;
}