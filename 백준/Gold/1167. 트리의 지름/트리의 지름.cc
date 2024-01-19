#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MAX 100001

using namespace std;

vector<pair<int, int>> tree[MAX]; // 트리의 간선 정보를 저장할 배열
bool visited[MAX]; // 방문 여부를 체크할 배열
int dist[MAX]; // 각 정점까지의 거리를 저장할 배열

// 트리의 지름을 찾는 함수
int findTreeDiameter(int start) {
    int maxDist = -1; // 최장 거리
    int farthestNode = 0; // 최장 거리의 끝 정점

    // BFS를 통해 임의의 점에서 가장 먼 점을 찾음
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : tree[cur]) {
            int nextNode = next.first;
            int nextDist = next.second;

            if (!visited[nextNode]) {
                dist[nextNode] = dist[cur] + nextDist;
                visited[nextNode] = true;
                if (maxDist < dist[nextNode]) {
                    maxDist = dist[nextNode];
                    farthestNode = nextNode;
                }
                q.push(nextNode);
            }
        }
    }
    // 다시 초기화
    fill(visited, visited + MAX, false);
    fill(dist, dist + MAX, 0);

    // 위에서 찾은 최장 거리의 끝 점에서 다시 BFS를 통해 트리의 지름 찾기
    q.push(farthestNode);
    visited[farthestNode] = true;
    maxDist = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : tree[cur]) {
            int nextNode = next.first;
            int nextDist = next.second;

            if (!visited[nextNode]) {
                dist[nextNode] = dist[cur] + nextDist;
                visited[nextNode] = true;
                maxDist = max(maxDist, dist[nextNode]);
                q.push(nextNode);
            }
        }
    }
    return maxDist;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, node, adjacent, weight;

    // 정점의 개수 입력
    cin >> V;

    // 트리의 간선 정보 입력
    for (int i = 1; i <= V; ++i) {
        cin >> node;
        while (1) {
            cin >> adjacent;
            if (adjacent == -1) break;
            cin >> weight;
            tree[node].push_back({adjacent, weight});
        }
    }
    // 트리의 지름 출력
    cout << findTreeDiameter(1);

    return 0;
}