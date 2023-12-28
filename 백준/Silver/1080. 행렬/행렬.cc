#include <iostream>
#include <vector>

using namespace std;

int diff(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            if (a[i][j] != b[i][j]) cnt++;
    return cnt;
}

void flip(vector<vector<int>>& matrix, int row, int col) {
    for (int i = row; i < row + 3; i++)
        for (int j = col; j < col + 3; j++)
            matrix[i][j] = 1 - matrix[i][j];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &a[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &b[i][j]);

    int ans = 0;

    for (int i = 0; i <= n - 3; i++)
        for (int j = 0; j <= m - 3; j++)
            if (a[i][j] != b[i][j]) {
                flip(a, i, j);
                ans++;
            }

    if (diff(a, b) == 0)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}