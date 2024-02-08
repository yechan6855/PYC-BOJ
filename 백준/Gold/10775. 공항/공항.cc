#include <iostream>
#include <vector>

using namespace std;

// 유니온 파인드(Union-Find) 자료구조 구현
struct UnionFind {
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    // 루트 노드 찾기
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    // 두 노드를 하나의 집합으로 합치기
    void unionNodes(int u, int v) {
        u = find(u);
        v = find(v);
        parent[u] = v;
    }
};

int main() {
    int G, P;
    cin >> G >> P;

    UnionFind uf(G);

    int ans = 0;
    for (int i = 0; i < P; ++i) {
        int gate;
        cin >> gate;

        int root = uf.find(gate);

        if (root == 0) break;  // 루트가 0이면 더 이상 도킹할 게이트가 없음

        uf.unionNodes(root, root - 1);
        ans++;
    }
    cout << ans << '\n';

    return 0;
}