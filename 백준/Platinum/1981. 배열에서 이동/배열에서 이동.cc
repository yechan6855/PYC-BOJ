#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> grid;

bool bfs(int min_val, int max_val) {
    if (grid[0][0] < min_val || grid[0][0] > max_val) return false;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == n - 1 && y == n - 1) return true;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                if (grid[nx][ny] >= min_val && grid[nx][ny] <= max_val) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int binary_search_diff() {
    int low = 0, high = 200;
    while (low < high) {
        int mid = (low + high) / 2;
        bool found = false;

        for (int min_val = 0; min_val + mid <= 200; ++min_val) {
            if (bfs(min_val, min_val + mid)) {
                found = true;
                break;
            }
        }

        if (found) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    cin >> n;
    grid.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << binary_search_diff() << endl;
    return 0;
}