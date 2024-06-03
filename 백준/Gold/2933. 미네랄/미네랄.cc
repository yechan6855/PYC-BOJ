#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define pi pair<int, int>
using namespace std;

int R, C, N;
vector<string> cave;
vector<int> heights;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve1() {
    for (const auto &row : cave) {
        cout << row << endl;
    }
}

bool isInRange(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void throwStick(int height, bool leftToRight) {
    int row = R - height;
    if (leftToRight) {
        for (int col = 0; col < C; col++) {
            if (cave[row][col] == 'x') {
                cave[row][col] = '.';
                break;
            }
        }
    } else {
        for (int col = C - 1; col >= 0; col--) {
            if (cave[row][col] == 'x') {
                cave[row][col] = '.';
                break;
            }
        }
    }
}

vector<pi> bfs(int sx, int sy, vector<vector<bool>> &visited) {
    queue<pi> q;
    vector<pi> cluster;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cluster.pb({x, y});

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInRange(nx, ny) && cave[nx][ny] == 'x' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return cluster;
}

void simulate(vector<pi> &cluster) {
    sort(cluster.begin(), cluster.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.fi > b.fi;
    });

    bool falling = true;
    while (falling) {
        for (const auto &block : cluster) {
            int x = block.fi;
            int y = block.se;
            if (x + 1 >= R || (cave[x + 1][y] == 'x' && find(cluster.begin(), cluster.end(), make_pair(x + 1, y)) == cluster.end())) {
                falling = false;
                break;
            }
        }
        if (falling) {
            for (auto &block : cluster) {
                cave[block.fi][block.se] = '.';
                block.fi++;
            }
        }
    }

    for (const auto &block : cluster) {
        cave[block.fi][block.se] = 'x';
    }
}

void solve2() {
    bool LR = true;
    for (int height : heights) {
        throwStick(height, LR);
        LR = !LR;

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        vector<vector<pi>> clusters;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (cave[i][j] == 'x' && !visited[i][j]) {
                    auto cluster = bfs(i, j, visited);
                    bool isFloating = true;
                    for (const auto &block : cluster) {
                        if (block.fi == R - 1) {
                            isFloating = false;
                            break;
                        }
                    }
                    if (isFloating) {
                        clusters.pb(cluster);
                    }
                }
            }
        }

        for (auto &cluster : clusters) {
            simulate(cluster);
        }
    }
}

int32_t main() {
    io;
    cin >> R >> C;
    cave.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> cave[i];
    }
    cin >> N;
    heights.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    solve2();
    solve1();
    return 0;
}