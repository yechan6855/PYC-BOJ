#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int board[51][51];
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            board[i][j] = row[j] - '0';
        }
    }

    int answer = 1; // 최소 크기는 1이므로 초기값을 1로 설정

    // 주어진 정사각형 모양의 숫자판에서 최대 크기의 정사각형 찾기
    for (int size = 1; size < min(N, M); ++size) {
        for (int i = 0; i < N - size; ++i) {
            for (int j = 0; j < M - size; ++j) {
                if (board[i][j] == board[i + size][j] &&
                    board[i][j] == board[i][j + size] &&
                    board[i][j] == board[i + size][j + size]) {
                    // 해당 위치에서 size 크기의 정사각형이 만들어질 수 있다면
                    answer = max(answer, (size + 1) * (size + 1));
                }
            }
        }
    }
    cout << answer << endl;

    return 0;
}