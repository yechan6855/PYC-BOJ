#include <bits/stdc++.h>
#define x first
#define y second
#define endl "\n"
#define pb push_back
#define pii pair<int,int>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int INF = 1e9 + 7;
int N, M, A, B, C;
vector<vector<pii>> adj;

bool solve(int maxCost) {
    vector<int> dist(N + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, A});
    dist[A] = 0;

    while (!pq.empty()) {
        int cost = pq.top().x;
        int here = pq.top().y;
        pq.pop();

        if (dist[here] < cost) continue;

        for (auto &edge : adj[here]) {
            int there = edge.x;
            int nextCost = edge.y;

            if (nextCost > maxCost) continue;

            if (dist[there] > dist[here] + nextCost) {
                dist[there] = dist[here] + nextCost;
                pq.push({dist[there], there});
            }
        }
    }

    return dist[B] <= C;
}

int main() {
    io;
    cin >> N >> M >> A >> B >> C;
    adj.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    int l = 1, r = 20;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (solve(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}