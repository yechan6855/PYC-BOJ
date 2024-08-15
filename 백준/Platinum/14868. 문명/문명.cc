#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int MAX = 2001;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int N, K;
int parent[MAX * MAX];
int c[MAX][MAX];
queue<pair<int, int>> q;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

bool in_range(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int solve() {
    int year = 0;
    int count = K;

    while (count > 1) {
        vector<pair<int, int>> new_civs;

        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            q.push({x, y});

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (!in_range(nx, ny)) continue;

                if (c[nx][ny] && find(c[x][y]) != find(c[nx][ny])) {
                    unite(c[x][y], c[nx][ny]);
                    count--;
                }
            }
        }

        if (count == 1) break;
        year++;

        qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (!in_range(nx, ny) || c[nx][ny]) continue;

                c[nx][ny] = c[x][y];
                new_civs.push_back({nx, ny});
            }
        }

        for (auto& p : new_civs) {
            q.push(p);
            for (int d = 0; d < 4; d++) {
                int nx = p.first + dx[d];
                int ny = p.second + dy[d];
                if (!in_range(nx, ny)) continue;

                if (c[nx][ny] && find(c[p.first][p.second]) != find(c[nx][ny])) {
                    unite(c[p.first][p.second], c[nx][ny]);
                    count--;
                }
            }
        }
    }

    return year;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 1; i <= N * N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= K; i++) {
        int x, y;
        cin >> y >> x;
        x--; y--;
        c[x][y] = i;
        q.push({x, y});
    }

    cout << solve() << endl;

    return 0;
}