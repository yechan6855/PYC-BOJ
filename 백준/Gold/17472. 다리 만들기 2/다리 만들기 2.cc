#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 10;
const int INF = 987654321;

int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int board[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> list[MAX];
priority_queue<tuple<int, int, int>> pq;
int parent[MAX];

int find(int node) {
    if (parent[node] == node) return node;
    else return parent[node] = find(parent[node]);
}

void unionSets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        parent[rootB] = rootA;
    }
}

void findBridge(int x, int y, int num, int dir, int len) {
    if (board[x][y] != 0 && board[x][y] != num) {
        if (len >= 2) pq.push({-len, num, board[x][y]});
        return;
    }

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) return;
    if (board[nx][ny] == num) return;
    findBridge(nx, ny, num, dir, len + 1);
}

int kruskal(int num) {
    for (int i = 1; i < num; i++) {
        parent[i] = i;
    }

    vector<bool> link(num, false);
    int result = 0;
    int bridge = 0;

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int len = -get<0>(current);
        int island1 = get<1>(current);
        int island2 = get<2>(current);

        int root1 = find(island1);
        int root2 = find(island2);

        if (root1 != root2) {
            unionSets(root1, root2);
            link[island1] = true;
            link[island2] = true;
            result += len;
            bridge++;
        }
    }

    if (result == 0) return -1;
    if (bridge != num - 2) return -1;
    return result;
}

void bfs(int x, int y, int num) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int currentX = current.first;
        int currentY = current.second;

        board[currentX][currentY] = num;
        list[num].push_back({currentX, currentY});

        for (int i = 0; i < 4; i++) {
            int nx = currentX + dx[i];
            int ny = currentY + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && board[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && board[i][j] == 1) {
                bfs(i, j, num);
                num++;
            }
        }
    }

    for (int i = 1; i < num; i++) {
        for (auto island : list[i]) {
            int x = island.first;
            int y = island.second;

            for (int k = 0; k < 4; k++) {
                findBridge(x, y, i, k, -1);
            }
        }
    }
    cout << kruskal(num) << endl;

    return 0;
}