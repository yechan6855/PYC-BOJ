#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

const int MAX = 505;
vector<int> graph[MAX];
int matched[MAX];
bool visited[MAX];
int n, k;

bool dfs(int node) {
    for (int next : graph[node]) {
        if (visited[next]) continue;
        visited[next] = true;
        if (matched[next] == 0 || dfs(matched[next])) {
            matched[next] = node;
            return true;
        }
    }
    return false;
}

int solve() {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) result++;
    }
    return result;
}

int main() {
    io;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        graph[r].push_back(c);
    }

    cout << solve() << endl;

    return 0;
}