#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;
int board[MAX][MAX], tempBoard[MAX][MAX];

void flip(int x, int y) {
    const int dx[5] = {0, 0, 0, -1, 1};
    const int dy[5] = {0, -1, 1, 0, 0};
    for (int i = 0; i < 5; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX) {
            tempBoard[nx][ny] ^= 1;
        }
    }
}

bool allOff() {
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
            if (tempBoard[i][j])
                return false;
    return true;
}

int solve() {
    int res = INT_MAX;
    for (int firstRow = 0; firstRow < (1 << MAX); ++firstRow) {
        int cnt = 0;
        memcpy(tempBoard, board, sizeof(board));

        for (int i = 0; i < MAX; ++i) {
            if (firstRow & (1 << i)) {
                flip(0, i);
                cnt++;
            }
        }

        for (int i = 1; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                if (tempBoard[i - 1][j]) {
                    flip(i, j);
                    cnt++;
                }
            }
        }

        if (allOff()) res = min(res, cnt);
    }
    return res == INT_MAX ? -1 : res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j) {
            char c;
            cin >> c;
            board[i][j] = (c == 'O');
        }

    cout << solve() << '\n';
    return 0;
}