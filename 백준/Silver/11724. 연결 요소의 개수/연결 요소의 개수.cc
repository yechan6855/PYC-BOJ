#include <bits/stdc++.h>

using namespace std;

vector<int> vec[1001];
int visited[1001];

int N, M;

void dfs(int vertex){
    visited[vertex] = 1;
    for(int i = 0; i < vec[vertex].size(); i++){
        int idx = vec[vertex][i];
        if(visited[idx] == 0){
            dfs(idx);
        }
    }
}

int main(){
    int u, v;
    int count = 0;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for(int i = 1; i <= N; i++){
        if(visited[i] == 0){
            count++;
            dfs(i);
        }
    }
    cout << count << endl;
}