#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define elif else if
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int INF = 1e9;
int R, C;
vector<string> info;
vector<pi> cars, parks;
int dist[100][100];
vi adj[100];
int car[100], park[100];
bool visited[100];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

bool in_bounds(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void bfs(int sx, int sy, int dist[][100]) {
    queue<pi> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (in_bounds(nx, ny) && info[nx][ny] != 'X' && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool dfs(int x) {
    for (int a : adj[x]) {
        if (!visited[a]) {
            visited[a] = true;
            if (park[a] == -1 || dfs(park[a])) {
                car[x] = a;
                park[a] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    io;
    cin >> R >> C;
    info.resize(R);

    for (int i = 0; i < R; ++i) {
        cin >> info[i];
        for (int j = 0; j < C; ++j) {
            if (info[i][j] == 'C') cars.pb({i, j});
            if (info[i][j] == 'P') parks.pb({i, j});
        }
    }

    int car_cnt = cars.size();
    int park_cnt = parks.size();

    if (car_cnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    vvi cost(car_cnt, vi(park_cnt, INF));

    for (int i = 0; i < car_cnt; ++i) {
        for (int j = 0; j < park_cnt; ++j) {
            for (int x = 0; x < R; ++x)
                for (int y = 0; y < C; ++y)
                    dist[x][y] = INF;
            bfs(cars[i].fi, cars[i].se, dist);
            cost[i][j] = dist[parks[j].fi][parks[j].se];
        }
    }

    int low = 0, high = R * C, answer = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        for (int i = 0; i < 100; ++i) adj[i].clear();
        for (int i = 0; i < car_cnt; ++i)
            for (int j = 0; j < park_cnt; ++j)
                if (cost[i][j] <= mid)
                    adj[i].pb(j);

        memset(car, -1, sizeof(car));
        memset(park, -1, sizeof(park));

        int cnt = 0;
        for (int i = 0; i < car_cnt; ++i) {
            memset(visited, false, sizeof(visited));
            if (dfs(i)) cnt++;
        }

        if (cnt == car_cnt) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}