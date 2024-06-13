#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pi pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct Point {
    int x, y;
};

int R, C;
vector<string> maze;
vvi Time1;
vvi Time2;
queue<Point> Queue1;
queue<Point> Queue2;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs1() {
    while (!Queue1.empty()) {
        Point curr = Queue1.front();
        Queue1.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
                if (Time1[nx][ny] == -1 && maze[nx][ny] != '#') {
                    Time1[nx][ny] = Time1[curr.x][curr.y] + 1;
                    Queue1.push({nx, ny});
                }
            }
        }
    }
}

int bfs2() {
    while (!Queue2.empty()) {
        Point curr = Queue2.front();
        Queue2.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
                if (Time2[nx][ny] == -1 && maze[nx][ny] != '#') {
                    if (Time1[nx][ny] == -1 || Time2[curr.x][curr.y] + 1 < Time1[nx][ny]) {
                        Time2[nx][ny] = Time2[curr.x][curr.y] + 1;
                        Queue2.push({nx, ny});
                    }
                }
            } else {
                return Time2[curr.x][curr.y] + 1;
            }
        }
    }
    return -1;
}

int main() {
    io;
    cin >> R >> C;
    maze.resize(R);
    Time1.assign(R, vi(C, -1));
    Time2.assign(R, vi(C, -1));

    Point Start;

    for (int i = 0; i < R; i++) {
        cin >> maze[i];
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'J') {
                Start = {i, j};
                Queue2.push(Start);
                Time2[i][j] = 0;
            } else if (maze[i][j] == 'F') {
                Queue1.push({i, j});
                Time1[i][j] = 0;
            }
        }
    }

    bfs1();
    int result = bfs2();

    if (result == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}