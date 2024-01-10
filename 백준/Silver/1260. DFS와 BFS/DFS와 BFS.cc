#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node) {
    check[node] = true;
    cout << node << " ";
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (check[next] == false) {
            dfs(next);
        }
    }
}
void bfs(int start) {
    queue<int> q;
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i=0; i<a[node].size(); i++) {
            int next = a[node][i];
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}
int main() {
    int n, m, start;
    cin >> n >> m >> start;
    for (int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    dfs(start);
    cout << '\n';
    memset(check,false,sizeof(check));
    bfs(start);
    return 0;
}