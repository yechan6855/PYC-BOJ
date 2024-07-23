#include <bits/stdc++.h>
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define io ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

bool solve(vi& line, int L) {
    int n = line.size();
    vi used(n, false);

    for (int i = 0; i < n - 1; ++i) {
        if (line[i] == line[i + 1]) continue;

        if (abs(line[i] - line[i + 1]) > 1) return false;

        if (line[i] < line[i + 1]) {
            for (int j = 0; j < L; ++j) {
                if (i - j < 0 || line[i] != line[i - j] || used[i - j]) return false;
                used[i - j] = true;
            }
        }
        else {
            for (int j = 1; j <= L; ++j) {
                if (i + j >= n || line[i + 1] != line[i + j] || used[i + j]) return false;
                used[i + j] = true;
            }
        }
    }

    return true;
}

int main() {
    io;
    int N, L;
    cin >> N >> L;

    vvi map(N, vi(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        if (solve(map[i], L)) {
            ++cnt;
        }
    }

    for (int j = 0; j < N; ++j) {
        vi col(N);
        for (int i = 0; i < N; ++i) {
            col[i] = map[i][j];
        }
        if (solve(col, L)) {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}