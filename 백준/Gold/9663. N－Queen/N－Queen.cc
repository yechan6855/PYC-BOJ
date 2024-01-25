#include <iostream>
#include <vector>
using namespace std;

int N;
int answer = 0;
vector<int> col;

bool isSafe(int row, int c) {
    for (int prev = 0; prev < row; prev++) {
        // 같은 열이거나 대각선에 위치한 퀸이 있는 경우
        if (col[prev] == c || abs(col[prev] - c) == row - prev)
            return false;
    }
    return true;
}
void solve(int row) {
    if (row == N) {
        // 마지막 행까지 퀸을 배치한 경우
        answer++;
        return;
    }

    for (int c = 0; c < N; c++) {
        if (isSafe(row, c)) {
            col[row] = c;  // 현재 행에 퀸을 배치
            solve(row + 1);  // 다음 행으로 이동
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    col.resize(N);

    solve(0);  // 첫 번째 행부터 시작

    cout << answer << "\n";

    return 0;
}