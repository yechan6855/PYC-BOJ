#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> v; // 간선을 저장하는 벡터
int dist[501]; // 최단 거리를 저장하는 배열

// 벨만-포드 알고리즘을 이용하여 음수 사이클 여부를 확인하는 함수
void bellmanFord(int n) {
    // 출발 지점부터 각 지점까지의 최단 거리 계산
    for (int i = 0; i < n; i++) {
        for (int pos = 0; pos < v.size(); pos++) {
            int from = v[pos].first.first;
            int to = v[pos].first.second;
            int cost = v[pos].second;

            // 최단 거리 업데이트
            if (dist[from] + cost < dist[to]) dist[to] = dist[from] + cost;
        }
    }
    // 음수 사이클 여부 확인
    for (int pos = 0; pos < v.size(); pos++) {
        int from = v[pos].first.first;
        int to = v[pos].first.second;
        int cost = v[pos].second;

        // 음수 사이클이 있는 경우 출력 후 종료
        if (dist[from] + cost < dist[to]) {
            cout << "YES\n";
            return;
        }
    }
    // 음수 사이클이 없는 경우 "NO" 출력
    cout << "NO\n";
}

int main() {
    int tc;
    cin >> tc;

    // 각 테스트 케이스 처리
    while (tc--) {
        // 초기화
        v.clear();
        int n, m, w;
        cin >> n >> m >> w;
        for (int i = 1; i <= n; i++) dist[i] = 987654321;

        // 도로 정보 입력
        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            v.push_back({{from, to}, cost});
            v.push_back({{to, from}, cost}); // 양방향 도로 추가
        }
        // 웜홀 정보 입력
        for (int i = 0; i < w; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            v.push_back({{from, to}, -cost}); // 웜홀은 음수 가중치
        }
        // 벨만-포드 알고리즘을 통해 음수 사이클 여부 확인
        bellmanFord(n);
    }
    return 0;
}