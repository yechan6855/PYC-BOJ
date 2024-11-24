#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 2005;
const int INF = 1e9;

int V, E;
vector<int> adj[MAX_V];
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
int cost[MAX_V][MAX_V], dist[MAX_V], parent[MAX_V];
bool inQueue[MAX_V];

void init() {
    for(int i = 0; i < MAX_V; i++) {
        adj[i].clear();
    }
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));
    memset(cost, 0, sizeof(cost));
}

void addEdge(int from, int to, int cap, int c) {
    adj[from].push_back(to);
    adj[to].push_back(from);
    capacity[from][to] = cap;
    cost[from][to] = c;
    cost[to][from] = -c;
}

pair<int,int> MCMF(int source, int sink) {
    int totalFlow = 0, totalCost = 0;

    while(true) {
        fill(dist, dist + MAX_V, INF);
        fill(parent, parent + MAX_V, -1);
        memset(inQueue, false, sizeof(inQueue));

        queue<int> q;
        dist[source] = 0;
        q.push(source);
        inQueue[source] = true;

        while(!q.empty()) {
            int here = q.front();
            q.pop();
            inQueue[here] = false;

            for(int there : adj[here]) {
                if(capacity[here][there] - flow[here][there] > 0 &&
                   dist[there] > dist[here] + cost[here][there]) {
                    dist[there] = dist[here] + cost[here][there];
                    parent[there] = here;
                    if(!inQueue[there]) {
                        q.push(there);
                        inQueue[there] = true;
                    }
                }
            }
        }

        if(parent[sink] == -1) break;

        int amount = INF;
        for(int p = sink; p != source; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }

        for(int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
            totalCost += amount * cost[parent[p]][p];
        }
        totalFlow += amount;
    }
    return {totalFlow, totalCost};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> V >> E) {
        init();

        for(int i = 0; i < E; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            int aIn = a * 2 - 1;
            int aOut = a * 2;
            int bIn = b * 2 - 1;
            int bOut = b * 2;

            if(adj[aIn].empty()) addEdge(aIn, aOut, 1, 0);
            if(adj[bIn].empty()) addEdge(bIn, bOut, 1, 0);

            addEdge(aOut, bIn, 1, c);
        }

        addEdge(1, 2, 2, 0);
        addEdge(V*2-1, V*2, 2, 0);

        pair<int,int> result = MCMF(1, V*2);
        cout << result.second << '\n';
    }
    return 0;
}