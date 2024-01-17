#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 8;
int N, M;
int map[MAX][MAX];
int tempMap[MAX][MAX];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int result = 0;

void copyMap() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            tempMap[i][j] = map[i][j];
        }
    }
}
void virusSpread() {
    queue<pair<int, int>> q;
    // 초기 바이러스 위치 큐에 삽입
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (tempMap[i][j] == 2) {
                q.push({ i, j });
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (tempMap[nx][ny] == 0) {
                    tempMap[nx][ny] = 2;
                    q.push({ nx, ny });
                }
            }
        }
    }
}
int getSafeArea() {
    int safeArea = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (tempMap[i][j] == 0) {
                safeArea++;
            }
        }
    }
    return safeArea;
}
void wallInstallation(int count) {
    if (count == 3) {
        copyMap(); // 맵 복사
        virusSpread(); // 바이러스 퍼뜨리기
        result = max(result, getSafeArea()); // 안전 영역 크기 갱신
        return;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 0) {
                map[i][j] = 1; // 벽 설치
                wallInstallation(count + 1);
                map[i][j] = 0; // 설치한 벽 다시 제거
            }
        }
    }
}
int main() {
    // 입력 받기
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }
    wallInstallation(0);

    cout << result << endl;

    return 0;
}