#include <iostream>
#define INF 500000
using namespace std;
int d[101][101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m, ans,a,b,minCnt = INF;
    cin >> n >> m;
    fill(&d[0][0],&d[100][100]+1,INF);
    for(int i=1;i<=n;i++){
        d[i][i]=0;
    }
    for(int i=0;i<m;i++){
        cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=n;j++){
            sum+=d[i][j];
        }
        if (sum < minCnt) {
            minCnt = sum;
            ans = i;
        }
    }
    cout << ans << '\n';
    return 0;
}