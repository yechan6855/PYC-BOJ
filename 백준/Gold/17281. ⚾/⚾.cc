#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> innings;
vector<int> playerOrder = {1, 2, 3, 4, 5, 6, 7, 8};
int maxScore = 0;

int simulateGame() {
    int score = 0;
    int currentHitter = 0;  // 현재 치는 선수의 인덱스

    for (int inning = 0; inning < n; ++inning) {
        int outCount = 0;
        vector<bool> bases(4, false);

        while (outCount < 3) {
            int result = innings[inning][playerOrder[currentHitter]];

            if (result == 0) {
                outCount++;
            } else {
                for (int i = 3; i >= 1; --i) {
                    if (bases[i]) {
                        if (i + result > 3) {
                            score++;
                            bases[i] = false;
                        } else {
                            bases[i + result] = true;
                            bases[i] = false;
                        }
                    }
                }

                if (result < 4) {
                    bases[result] = true;
                } else {
                    score++;
                }
            }

            currentHitter = (currentHitter + 1) % 9;
        }
    }

    return score;
}

int main() {
    cin >> n;
    innings.resize(n, vector<int>(9));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> innings[i][j];
        }
    }

    do {
        // 4번 타자는 항상 1번 선수로 설정
        playerOrder.insert(playerOrder.begin() + 3, 0);

        int score = simulateGame();
        maxScore = max(maxScore, score);

        // 원래 순서로 복구
        playerOrder.erase(playerOrder.begin() + 3);
    } while (next_permutation(playerOrder.begin(), playerOrder.end()));

    cout << maxScore << endl;

    return 0;
}