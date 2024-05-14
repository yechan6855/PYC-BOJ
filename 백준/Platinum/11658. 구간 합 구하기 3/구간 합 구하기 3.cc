#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

class FenwickTree2D {
public:
    FenwickTree2D(int n) : n(n), tree(n + 1, vector<int>(n + 1, 0)) {}

    void update(int x, int y, int delta) {
        for (int i = x; i <= n; i += (i & -i)) {
            for (int j = y; j <= n; j += (j & -j)) {
                tree[i][j] += delta;
            }
        }
    }

    int query(int x, int y) {
        int sum = 0;
        for (int i = x; i > 0; i -= (i & -i)) {
            for (int j = y; j > 0; j -= (j & -j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    int query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }

private:
    int n;
    vector<vector<int>> tree;
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N + 1, vector<int>(N + 1));
    FenwickTree2D fenwickTree(N);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> matrix[i][j];
            fenwickTree.update(i, j, matrix[i][j]);
        }
    }

    for (int i = 0; i < M; ++i) {
        int w;
        cin >> w;
        if (w == 0) {
            int x, y, c;
            cin >> x >> y >> c;
            int delta = c - matrix[x][y];
            matrix[x][y] = c;
            fenwickTree.update(x, y, delta);
        } else if (w == 1) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << fenwickTree.query(x1, y1, x2, y2) << endl;
        }
    }

    return 0;
}