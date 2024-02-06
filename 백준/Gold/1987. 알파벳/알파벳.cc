#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
const int dy[] = {0, 0, -1, 1};

int R, C;
vector<string> board;
vector<bool> visited(26, false); // 알파벳의 방문 여부를 저장하는 배열

int dfs(int x, int y) {
    int result = 1;

    // 현재 알파벳 방문 처리
    visited[board[x][y] - 'A'] = true;

    // 상, 하, 좌, 우로 이동
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 범위 체크 및 방문 여부 확인
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[board[nx][ny] - 'A']) {
            result = max(result, 1 + dfs(nx, ny));
        }
    }

    // 현재 알파벳 방문 처리 취소
    visited[board[x][y] - 'A'] = false;

    return result;
}
int main() {
    cin >> R >> C;
    board.resize(R);

    for (int i = 0; i < R; ++i) {
        cin >> board[i];
    }

    int answer = dfs(0, 0);

    cout << answer << endl;

    return 0;
}