#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

queue<pair<int, int>> q;
int N, M, K;
int cabbage[50][50];
bool visited[50][50];

void bfs(int xx, int yy) {
	q.push({ xx, yy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && cabbage[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}
void init() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
			cabbage[i][j] = 0;
		}
	}
}
int main(void) {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		init();

		cin >> M >> N >> K;
		int cnt = 0;

		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> y >> x;
			cabbage[x][y] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cabbage[i][j] == 1 && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}