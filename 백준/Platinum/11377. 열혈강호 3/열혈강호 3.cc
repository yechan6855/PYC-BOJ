#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;

int N, M, K;
vector<int> adj[MAXN + 1];
int work[MAXM + 1];
bool visited[MAXN + 1];

bool dfs(int x) {
    for (int i = 0; i < adj[x].size(); ++i) {
        int t = adj[x][i];
        if (visited[t]) continue;
        visited[t] = true;
        if (work[t] == 0 || dfs(work[t])) {
            work[t] = x;
            return true;
        }
    }
    return false;
}

int bipartite_matching() {
    memset(work, 0, sizeof(work));
    int match = 0;
    for (int i = 1; i <= N; ++i) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) match++;
    }
    return match;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            int job;
            cin >> job;
            adj[i].push_back(job);
        }
    }

    int match = bipartite_matching();

    int extra_match = 0;
    for (int i = 1; i <= N; ++i) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) {
            extra_match++;
            if (extra_match == K) break;
        }
    }

    cout << match + extra_match << endl;

    return 0;
}