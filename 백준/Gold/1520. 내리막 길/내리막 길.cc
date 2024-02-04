#include <iostream>
#include <vector>

using namespace std;

const int MAX = 500;
int map[MAX][MAX];
int dp[MAX][MAX];
int M, N;

int dfs(int x, int y) {
    if (x == M - 1 && y == N - 1) {
        return 1; // 목적지에 도달하면 1을 반환
    }

    if (dp[x][y] != -1) {
        return dp[x][y]; // 이미 계산한 경우 저장된 값을 반환
    }

    dp[x][y] = 0; // 아직 계산되지 않은 경우 0으로 초기화

    // 상, 하, 좌, 우 이동
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 범위 내에 있고, 내리막이라면 dfs 호출
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[nx][ny] < map[x][y]) {
            dp[x][y] += dfs(nx, ny);
        }
    }

    return dp[x][y]; // 현재 위치에서의 경로 수 반환
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            dp[i][j] = -1; // dp 배열 초기화
        }
    }
    cout << dfs(0, 0) << endl;

    return 0;
}