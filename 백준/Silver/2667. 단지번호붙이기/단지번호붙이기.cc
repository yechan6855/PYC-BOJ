#include <bits/stdc++.h>

using namespace std;

int n;
int arr[26][26];
int visited[26][26];
int cnt = 0;

vector<int> v;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y){
    visited[x][y] = 1;
    cnt++;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(arr[nx][ny] == 1 && visited[nx][ny] == 0){
                dfs(nx,ny);
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            arr[i][j] = s[j] - '0';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && visited[i][j] == 0){
                cnt = 0;
                dfs(i,j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}