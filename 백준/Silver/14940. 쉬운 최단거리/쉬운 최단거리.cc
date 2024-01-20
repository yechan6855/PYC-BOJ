#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int** map = new int* [n];
	bool** visit = new bool* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		visit[i] = new bool[m];
	}
		

	int target_x, target_y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			visit[i][j] = 0;
			if (map[i][j] == 2) {
				target_x = i;
				target_y = j;
				map[i][j] = 0;
			}
		}
	}

	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	
	queue<pair<int, int>> q;
	q.push(make_pair(target_x, target_y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					if (map[nx][ny] == 0)
						continue;
					else {
						map[nx][ny] = map[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0) {
				if (map[i][j] != 0) 
					map[i][j] = -1;
			}
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}