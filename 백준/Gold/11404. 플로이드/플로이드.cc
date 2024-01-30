#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 무한대 값으로 사용할 상수

int main() {
    int n, m;
    cin >> n >> m;

    // 그래프의 초기화
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    // 자기 자신으로 가는 비용은 0으로 초기화
    for (int i = 1; i <= n; ++i) {
        graph[i][i] = 0;
    }

    // 간선 정보 입력
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    // 플로이드-와샬 알고리즘
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (graph[i][j] == INF) {
                cout << "0 ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}