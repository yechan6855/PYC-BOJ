#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> adj(N+1, vector<int>());

    for(int i=0; i<M; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=N; ++i){
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    vector<bool> visited(N+1, false);
    vector<int> depth(N+1, -1);
    vector<int> ti(N+1, 0);
    stack<pair<int, int>> s;

    s.push({R, 0});
    int counter = 1;

    while(!s.empty()){
        pair<int, int> current = s.top();
        s.pop();
        int node = current.first;
        int d = current.second;

        if(!visited[node]){
            visited[node] = true;
            depth[node] = d;
            ti[node] = counter++;

            for(auto it = adj[node].rbegin(); it != adj[node].rend(); ++it){
                int neighbor = *it;

                if(!visited[neighbor]){
                    s.push({neighbor, d+1});
                }
            }
        }
    }

    ll sum = 0;

    for(int i=1; i<=N; ++i){
        sum += (ll)depth[i] * ti[i];
    }

    cout << sum;
}