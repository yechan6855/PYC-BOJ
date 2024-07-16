#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAX = 500;
int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int result = 0;

void dfs(int x, int y, int sum, int cnt) {
    if (cnt == 4) {
        result = max(result, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, sum + board[nx][ny], cnt + 1);
            visited[nx][ny] = false;
        }
    }
}

void check(int x, int y) {
    if (x + 2 < n && y + 1 < m)
        result = max(result, board[x][y] + board[x+1][y] + board[x+2][y] + board[x+1][y+1]);
    if (x + 2 < n && y - 1 >= 0)
        result = max(result, board[x][y] + board[x+1][y] + board[x+2][y] + board[x+1][y-1]);
    if (x + 1 < n && y + 2 < m)
        result = max(result, board[x][y] + board[x][y+1] + board[x][y+2] + board[x+1][y+1]);
    if (x - 1 >= 0 && y + 2 < m)
        result = max(result, board[x][y] + board[x][y+1] + board[x][y+2] + board[x-1][y+1]);
}

int main() {
    io;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i, j, board[i][j], 1);
            visited[i][j] = false;
            check(i, j);
        }
    }

    cout << result << endl;
    return 0;
}