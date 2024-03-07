#include <iostream>
#include <vector>

using namespace std;

int w(int a, int b, int c, vector<vector<vector<int>>>& memo) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return memo[20][20][20] = w(20, 20, 20, memo);
    }
    if (memo[a][b][c] != 0) {
        return memo[a][b][c];
    }
    if (a < b && b < c) {
        return memo[a][b][c] = w(a, b, c - 1, memo) + w(a, b - 1, c - 1, memo) - w(a, b - 1, c, memo);
    }
    return memo[a][b][c] = w(a - 1, b, c, memo) + w(a - 1, b - 1, c, memo) + w(a - 1, b, c - 1, memo) - w(a - 1, b - 1, c - 1, memo);
}

int main() {
    vector<vector<vector<int>>> memo(21, vector<vector<int>>(21, vector<int>(21, 0)));
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c, memo) << '\n';
    }
    return 0;
}