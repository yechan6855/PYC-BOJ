#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int N;
vvi board;
vvi visited;
int result[2];
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};

bool isSafe(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

void dfs(int x, int y, int color, int count) {
    result[color] = max(result[color], count);
    for (int i = x; i < N; i++) {
        for (int j = (i == x ? y : 0); j < N; j++) {
            if ((i + j) % 2 == color && board[i][j] == 1 && !visited[i][j]) {
                bool canPlace = true;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i, ny = j;
                    while (isSafe(nx, ny)) {
                        if (visited[nx][ny]) {
                            canPlace = false;
                            break;
                        }
                        nx += dx[dir];
                        ny += dy[dir];
                    }
                    if (!canPlace) break;
                }
                if (canPlace) {
                    visited[i][j] = true;
                    dfs(i, j, color, count + 1);
                    visited[i][j] = false;
                }
            }
        }
    }
}

int32_t main() {
    io;
    cin >> N;
    board.resize(N, vi(N));
    visited.resize(N, vi(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    dfs(0, 0, 0, 0);
    dfs(0, 1, 1, 0);
    cout << result[0] + result[1] << endl;
    return 0;
}