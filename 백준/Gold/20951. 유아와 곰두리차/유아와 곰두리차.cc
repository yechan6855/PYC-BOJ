#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define MOD 1000000007
using namespace std;

signed main() {
    io;
    int N, M;
    cin >> N >> M;

    vvi graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    vvi dp(8, vi(N + 1, 0));

    for (int i = 1; i <= N; ++i) {
        dp[0][i] = 1;
    }

    for (int k = 1; k <= 7; ++k) {
        for (int v = 1; v <= N; ++v) {
            for (int u : graph[v]) {
                dp[k][v] = (dp[k][v] + dp[k - 1][u]) % MOD;
            }
        }
    }

    int result = 0;
    for (int v = 1; v <= N; ++v) {
        result = (result + dp[7][v]) % MOD;
    }

    cout << result << endl;

    return 0;
}