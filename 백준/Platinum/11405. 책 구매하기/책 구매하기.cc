#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define MOD 9901
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAX = 402;
const int INF = INT_MAX;

struct Edge {
    int to, capacity, cost, reverse;
};

vector<Edge> graph[MAX];
int dist[MAX], parent[MAX], parentEdge[MAX];
bool inQueue[MAX];
int source, sink;

void addEdge(int from, int to, int capacity, int cost) {
    Edge forward = {to, capacity, cost, (int)graph[to].size()};
    Edge backward = {from, 0, -cost, (int)graph[from].size()};
    graph[from].push_back(forward);
    graph[to].push_back(backward);
}

bool spfa() {
    fill(dist, dist + MAX, INF);
    memset(inQueue, false, sizeof(inQueue));
    qi q;
    q.push(source);
    dist[source] = 0;
    inQueue[source] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;
        for (int i = 0; i < graph[u].size(); i++) {
            Edge &e = graph[u][i];
            if (e.capacity > 0 && dist[e.to] > dist[u] + e.cost) {
                dist[e.to] = dist[u] + e.cost;
                parent[e.to] = u;
                parentEdge[e.to] = i;
                if (!inQueue[e.to]) {
                    q.push(e.to);
                    inQueue[e.to] = true;
                }
            }
        }
    }
    return dist[sink] != INF;
}

pii MaxFlow() {
    int totalFlow = 0, totalCost = 0;
    while (spfa()) {
        int flow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            flow = min(flow, graph[parent[v]][parentEdge[v]].capacity);
        }
        for (int v = sink; v != source; v = parent[v]) {
            Edge &e = graph[parent[v]][parentEdge[v]];
            e.capacity -= flow;
            graph[v][e.reverse].capacity += flow;
            totalCost += flow * e.cost;
        }
        totalFlow += flow;
    }
    return {totalFlow, totalCost};
}

int main() {
    io;
    int N, M;
    cin >> N >> M;
    source = 0;
    sink = N + M + 1;

    for (int i = 1; i <= N; i++) {
        int demand;
        cin >> demand;
        addEdge(M + i, sink, demand, 0);
    }

    for (int j = 1; j <= M; j++) {
        int supply;
        cin >> supply;
        addEdge(source, j, supply, 0);
    }

    for (int j = 1; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            int cost;
            cin >> cost;
            addEdge(j, M + i, INF, cost);
        }
    }
    pii result = MaxFlow();
    cout << result.se << endl;

    return 0;
}