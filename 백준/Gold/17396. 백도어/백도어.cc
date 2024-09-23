#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for(int &x : a) cin >> x;
    
    vector<vector<pair<int, int>>> adj(N);
    for(int i=0; i<M; ++i){
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].emplace_back(v, t);
        adj[v].emplace_back(u, t);
    }
    
    vector<ll> dist(N, INF);
    dist[0] = 0;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, std::greater<pair<ll, int>>> pq;
    pq.emplace(0, 0);
    
    while(!pq.empty()){
        auto [current_dist, u] = pq.top();
        pq.pop();

        if(u == N-1){
            break;
        }

        if(current_dist > dist[u]){
            continue;
        }

        for(auto &[v, t] : adj[u]){
            if(a[v] == 0 || v == N-1){
                if(dist[v] > dist[u] + (ll)t){
                    dist[v] = dist[u] + (ll)t;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }

    if(dist[N-1] != INF){
        cout << dist[N-1];
    }
    else{
        cout << "-1";
    }
}