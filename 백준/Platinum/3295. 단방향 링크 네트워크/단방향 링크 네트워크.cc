#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int,int>
#define mi map<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAX = 1000;
vi graph[MAX];
int b[MAX];
bool visited[MAX];

bool dfs(int x){
    visited[x] = true;
    for (int idx : graph[x]) {
        if (b[idx] == -1 || (!visited[b[idx]] && dfs(b[idx]))) {
            b[idx] = x;
            return true;
        }
    }
    return false;
}

int32_t main() {
    io;
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i){
            graph[i].clear();
        }

        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            graph[u].pb(v);
        }

        memset(b, -1, sizeof(b));
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            memset(visited, 0, sizeof(visited));
            if(dfs(i)){
                ++ans;
            }
        }

        cout << ans << endl;
    }
    return 0;
}