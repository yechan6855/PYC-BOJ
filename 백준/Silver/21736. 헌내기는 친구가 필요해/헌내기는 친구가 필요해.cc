#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<char>> campus(N, vector<char>(M));
    int start_x = -1, start_y = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> campus[i][j];

            if (campus[i][j] == 'I') {
                start_x = i;
                start_y = j;
            }
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    int meet_cnt = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (campus[nx][ny] == 'X') continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});

            if (campus[nx][ny] == 'P') {
                meet_cnt++;
            }
        }
    }

    if (meet_cnt == 0) {
        cout << "TT" << '\n';
    } else {
        cout << meet_cnt << '\n';
    }

    return 0;
}