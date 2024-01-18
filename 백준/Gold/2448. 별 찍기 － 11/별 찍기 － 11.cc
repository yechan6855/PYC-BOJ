#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 별을 출력하는 함수
void printStar(int n, int x, int y, vector<vector<char>>& arr) {
    if (n == 3) {
        arr[x][y] = '*';
        arr[x + 1][y - 1] = '*';
        arr[x + 1][y + 1] = '*';
        arr[x + 2][y - 2] = '*';
        arr[x + 2][y - 1] = '*';
        arr[x + 2][y] = '*';
        arr[x + 2][y + 1] = '*';
        arr[x + 2][y + 2] = '*';
        return;
    }
    int newN = n / 2;
    printStar(newN, x, y, arr);
    printStar(newN, x + newN, y - newN, arr);
    printStar(newN, x + newN, y + newN, arr);
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> arr(n, vector<char>(2 * n - 1, ' '));

    printStar(n, 0, n - 1, arr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return 0;
}