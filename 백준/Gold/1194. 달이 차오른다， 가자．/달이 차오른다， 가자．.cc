#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int ans = -1;

char map[50][50];
int visited[50][50][1 << 6];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int key[6] = { 0,0,0,0,0,0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j];
            if (map[i][j] == '0') {
                x = i;
                y = j;
            }
        }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({ {x,y},0 });
    visited[x][y][0] = 1;
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        if (map[x][y] == '1') {
            ans = visited[x][y][z] - 1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == '#') continue;
            if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f') {
                nz = z | (1 << (map[nx][ny] - 'a'));
            }
            if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F') {
                if (!(z & (1 << (map[nx][ny] - 'A')))) continue;
            }
            if (visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({ {nx,ny},nz });
        }
    }
    cout << ans;
    
    return 0;
}