#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 10001;

vector<pair<int, int>> tree[MAX];
bool visited[MAX];
int result = 0;
int farthestNode = 0;

void dfs(int node, int distance) {
    if (visited[node]) return;

    visited[node] = true;

    if (distance > result) {
        result = distance;
        farthestNode = node;
    }

    for (auto neighbor : tree[node]) {
        int nextNode = neighbor.first;
        int nextDistance = neighbor.second;

        dfs(nextNode, distance + nextDistance);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int parent, child, weight;
        cin >> parent >> child >> weight;

        tree[parent].push_back({child, weight});
        tree[child].push_back({parent, weight});
    }
    // 첫 번째 DFS: 아무 노드에서 출발하여 가장 먼 노드(farthestNode) 찾기
    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    // 두 번째 DFS: 가장 먼 노드에서 출발하여 트리의 지름 구하기
    memset(visited, false, sizeof(visited));
    result = 0;
    dfs(farthestNode, 0);

    cout << result << '\n';

    return 0;
}