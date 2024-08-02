#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX=1001;
int n,m;
vector<int> graph[MAX];
int matched[MAX];
bool visited[MAX];

bool dfs(int node){
    for(int work:graph[node]){
        if(visited[work]) continue;
        visited[work]=true;
        if(matched[work]==0||dfs(matched[work])){
            matched[work]=node;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    for(int i=1; i<=n; i++){
        int cnt;
        cin>>cnt;
        for(int j=0; j<cnt; j++){
            int work;
            cin>>work;
            graph[i].push_back(work);
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<2; j++){
            memset(visited,false,sizeof(visited));
            if(dfs(i)) ans++;
        }
    }
    cout<<ans<<endl;
}