#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;

int N, M, K;
vector<pair<int, int>> graph[10001];
ll dp[10001][21];

void dijkstra() {
    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push({0, {1, 0}});
    dp[1][0] = 0;

    while (!pq.empty()) {
        ll cost = -pq.top().first;
        int cur = pq.top().second.first;
        int paved = pq.top().second.second;
        pq.pop();

        if (dp[cur][paved] < cost) continue;

        for (auto &next : graph[cur]) {
            int nextNode = next.first;
            int nextCost = next.second;

            if (paved < K && dp[nextNode][paved + 1] > cost) {
                dp[nextNode][paved + 1] = cost;
                pq.push({-cost, {nextNode, paved + 1}});
            }

            if (dp[nextNode][paved] > cost + nextCost) {
                dp[nextNode][paved] = cost + nextCost;
                pq.push({-(cost + nextCost), {nextNode, paved}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= K; j++)
            dp[i][j] = INF;

    dijkstra();

    ll ans = INF;
    for (int i = 0; i <= K; i++)
        ans = min(ans, dp[N][i]);

    cout << ans << "\n";

    return 0;
}