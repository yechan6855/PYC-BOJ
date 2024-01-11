#include <iostream>
#include <cstring>
using namespace std;

int N, M, ans;
bool circle;
char board[51][51];
int visited[51][51];
int dp[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int a, int b) {
    if(board[a][b] =='H') return 0;
    if(a<0 || a>=N || b<0 || b>=M) return 0;
        if(visited[a][b]) {
        circle = true;
        return -1;
    }
    int &count = dp[a][b];
    if(count != -1) return count;
    visited[a][b] = 1;
    for(int i=0; i<4; i++) {
        int xx = a + dx[i] * (board[a][b] - '0');
        int yy = b + dy[i] * (board[a][b] - '0');
       
        count = max(count, dfs(xx, yy)+1);
    }
    visited[a][b] = 0;
    return count;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            cin>>board[i][j];
    }
    ans = dfs(0, 0);
    if (circle) cout<<-1;
    else cout<<ans;

    return 0;
}