#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;

struct Edge {
    int to;
    int rev;
    int cap;
    ll cost;
};

void add_edge(vector<vector<Edge>> &graph, int from, int to, int cap, ll cost) {
    Edge a = {to, (int)graph[to].size(), cap, cost};
    Edge b = {from, (int)(graph[from].size()), 0, -cost};
    graph[from].push_back(a);
    graph[to].push_back(b);
}

pair<int, ll> min_cost_max_flow(vector<vector<Edge>> &graph, int S, int T) {
    int n = graph.size();
    vector<ll> potential(n, 0);
    ll flow = 0;
    ll cost = 0;

    while (true) {
        vector<ll> dist(n, INF);
        vector<int> prevv(n, -1);
        vector<int> preve(n, -1);

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, std::greater<pair<ll, int>>> pq;

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (int i = 0; i < graph[u].size(); ++i) {
                Edge &e = graph[u][i];
                if (e.cap > 0 && dist[e.to] > dist[u] + e.cost + potential[u] - potential[e.to]) {
                    dist[e.to] = dist[u] + e.cost + potential[u] - potential[e.to];
                    prevv[e.to] = u;
                    preve[e.to] = i;
                    pq.push({dist[e.to], e.to});
                }
            }
        }

        if (dist[T] == INF) break;
        
        for (int v = 0; v < n; ++v) {
            if (dist[v] < INF)
                potential[v] += dist[v];
        }
        
        ll add_flow = INF;
        int v = T;
        while (v != S) {
            int u = prevv[v];
            int idx = preve[v];
            add_flow = min(add_flow, (ll)graph[u][idx].cap);
            v = u;
        }
        
        flow += add_flow;
        cost += add_flow * potential[T];
        v = T;
        while (v != S) {
            int u = prevv[v];
            int idx = preve[v];
            graph[u][idx].cap -= add_flow;
            graph[v][graph[u][idx].rev].cap += add_flow;
            v = u;
        }
    }

    return {flow, cost};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for(int &x : A) cin >> x;
    
    vector<int> B(M);
    for(int &x : B) cin >> x;
    
    vector<vector<int>> C(M, vector<int>(N));
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            cin >> C[i][j];
        }
    }
    
    vector<vector<ll>> D(M, vector<ll>(N));
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            cin >> D[i][j];
        }
    }
    
    int S = 0;
    int T = M + N + 1;
    int total_nodes = M + N + 2;

    vector<vector<Edge>> graph(total_nodes, vector<Edge>());
    
    for(int i=0; i<M; ++i){
        add_edge(graph, S, 1 + i, B[i], 0);
    }
    
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            if(C[i][j] > 0){
                add_edge(graph, 1 + i, 1 + M + j, C[i][j], D[i][j]);
            }
        }
    }
    
    for(int j=0; j<N; ++j){
        add_edge(graph, 1 + M + j, T, A[j], 0);
    }

    pair<int, ll> result = min_cost_max_flow(graph, S, T);
    
    int total_books = accumulate(A.begin(), A.end(), 0);

    cout << result.first << "\n" << result.second << "\n";
}