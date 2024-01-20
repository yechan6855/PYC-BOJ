#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 1e9+7
#define pii pair<int, int>
 
typedef long long ll;
// typedef pair<int, int> pii;
 
using namespace std;
 
int N, E, V1, V2;
vector<pii > adj[801];
vector<int> dist;
 
void input(){
    int a, b, c;
    cin >> N >> E;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> V1 >> V2;
}
 
int dijkstra(int st, int ed){
    dist = vector<int>(N+1, INF);
    priority_queue<pii, vector<pii >, greater<pii > > que;
    que.push({0, st});
    
    dist[st] = 0;
    
    while(!que.empty()){
        int now = que.top().second;
        int cost = que.top().first;
        que.pop();
        
        if(cost > dist[now]) continue;
        
        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].second;
            int next_cost = adj[now][i].first + cost;
            
            if(next_cost < dist[next]){
                dist[next] = next_cost;
                que.push({next_cost, next});
            }
        }
    }
    
    return dist[ed];
}
 
void solve(){
    int res1, res2;
    int a1 = dijkstra(1, V1);
    int a2 = dijkstra(V1, V2);
    int a3 = dijkstra(V2, N);
    if(a1 == INF || a2 == INF || a3 == INF) res1 = INF;
    else res1 = a1 + a2 + a3;
    
    int b1 = dijkstra(1, V2);
    int b2 = dijkstra(V2, V1);
    int b3 = dijkstra(V1, N);
    if(b1 == INF || b2 == INF || b3 == INF) res2 = INF;
    else res2 = b1 + b2 + b3;
    
    if(res1 == INF && res2 == INF) cout << -1;
    else cout << min(res1, res2);
}
int main(){
    fasti
    input();
    solve();
    
    return 0;
}