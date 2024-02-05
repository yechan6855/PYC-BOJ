#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N;
int map[100][100];
int label[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void labeling(int x, int y, int islandNum) {
    queue<pair<int, int>> q;
    q.push({x, y});
    label[x][y] = islandNum;

    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                if (map[nextX][nextY] == 1 && label[nextX][nextY] == 0) {
                    q.push({nextX, nextY});
                    label[nextX][nextY] = islandNum;
                }
            }
        }
    }
}

int findMinBridge() {
    int minBridge = N * N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (label[i][j] != 0) {
                int startLabel = label[i][j];

                queue<pair<pair<int, int>, int>> q;
                q.push({{i, j}, 0});

                bool visited[100][100] = {false};
                visited[i][j] = true;

                while (!q.empty()) {
                    int currentX = q.front().first.first;
                    int currentY = q.front().first.second;
                    int bridgeLength = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nextX = currentX + dx[k];
                        int nextY = currentY + dy[k];

                        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                            if (!visited[nextX][nextY]) {
                                visited[nextX][nextY] = true;

                                if (label[nextX][nextY] == 0) {
                                    q.push({{nextX, nextY}, bridgeLength + 1});
                                } else if (label[nextX][nextY] != startLabel) {
                                    minBridge = min(minBridge, bridgeLength);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return minBridge;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int islandNum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && label[i][j] == 0) {
                islandNum++;
                labeling(i, j, islandNum);
            }
        }
    }
    cout << findMinBridge() << endl;

    return 0;
}