#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int SIZE = 501;
const int INF = 1e9;

int grid[SIZE][SIZE];
int life[SIZE][SIZE];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Point {
    int x, y, l;
    Point(int _x, int _y, int _l) : x(_x), y(_y), l(_l) {}
    bool operator>(const Point& other) const {
        return l > other.l;
    }
};

void solve(int x1, int y1, int x2, int y2, int value) {
    for (int i = min(x1, x2); i <= max(x1, x2); i++) {
        for (int j = min(y1, y2); j <= max(y1, y2); j++) {
            grid[i][j] = max(grid[i][j], value);
        }
    }
}

int dijkstra() {
    priority_queue<Point, vector<Point>, greater<Point>> pq;
    pq.push(Point(0, 0, 0));
    life[0][0] = 0;

    while (!pq.empty()) {
        Point cur = pq.top();
        pq.pop();

        if (cur.x == 500 && cur.y == 500) return cur.l;

        if (cur.l > life[cur.x][cur.y]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx > 500 || ny < 0 || ny > 500) continue;
            if (grid[nx][ny] == 2) continue;

            int nl = cur.l + (grid[nx][ny] == 1);

            if (nl < life[nx][ny]) {
                life[nx][ny] = nl;
                pq.push(Point(nx, ny, nl));
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;

    for (int i = 0; i <= 500; i++) {
        fill(life[i], life[i] + 501, INF);
    }

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        solve(x1, y1, x2, y2, 1);
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        solve(x1, y1, x2, y2, 2);
    }

    cout << dijkstra() << endl;

    return 0;
}