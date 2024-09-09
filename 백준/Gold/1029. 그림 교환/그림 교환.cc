#include <bits/stdc++.h>
using namespace std;

int n;
int cost[15][15];
int dp[15][1<<15][10];

int dfs(int cur, int visited, int price) {
    if (visited == (1<<n)-1) return 1;

    int &ret = dp[cur][visited][price];
    if (ret != -1) return ret;

    ret = 1;
    for (int next = 0; next < n; next++) {
        if (visited & (1<<next)) continue;
        if (cost[cur][next] < price) continue;
        ret = max(ret, 1 + dfs(next, visited | (1<<next), cost[cur][next]));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            cost[i][j] = s[j] - '0';
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1, 0) << "\n";

    return 0;
}