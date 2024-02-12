#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
    int age;
    bool alive;
};

int N, M, K;
int A[11][11];  // 겨울에 추가되는 양분 정보
int land[11][11];  // 현재 양분 정보
vector<Tree> trees[11][11];  // 나무 정보

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void spring() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            sort(trees[i][j].begin(), trees[i][j].end(), [](const Tree &a, const Tree &b) {
                return a.age < b.age;
            });

            vector<Tree> newTrees;
            int dead = 0;

            for (int k = 0; k < trees[i][j].size(); ++k) {
                if (trees[i][j][k].age <= land[i][j]) {
                    land[i][j] -= trees[i][j][k].age;
                    newTrees.push_back({ trees[i][j][k].age + 1, true });
                } else {
                    dead += trees[i][j][k].age / 2;
                }
            }

            trees[i][j] = newTrees;
            land[i][j] += dead;
        }
    }
}

void summer() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < trees[i][j].size(); ++k) {
                if (!trees[i][j][k].alive) {
                    land[i][j] += trees[i][j][k].age / 2;
                }
            }
        }
    }
}

void fall() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < trees[i][j].size(); ++k) {
                if (trees[i][j][k].age % 5 == 0) {
                    for (int d = 0; d < 8; ++d) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                            trees[nx][ny].push_back({ 1, true });
                        }
                    }
                }
            }
        }
    }
}

void winter() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            land[i][j] += A[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
            land[i][j] = 5;
        }
    }

    for (int i = 0; i < M; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x][y].push_back({ z, true });
    }

    for (int year = 0; year < K; ++year) {
        spring();
        summer();
        fall();
        winter();
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            answer += trees[i][j].size();
        }
    }
    cout << answer << '\n';

    return 0;
}