#include <iostream>
#include <queue>
#include <tuple>
#define MAX 102
using namespace std;

int M,N,H;
int days=0;
int tomato=0;
bool flag=false;
int arr[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int dx[] = {0,0,1,-1,0,0};
int dy[] = {1,-1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};
queue<tuple<int,int,int>> q;

int main()
{
    cin >> M >> N >> H;
    for(int i=0;i<H;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<M;k++) {
                cin >> arr[i][j][k];
                if(arr[i][j][k]==0) tomato++;
                if(arr[i][j][k]==1) {
                    q.push({i,j,k});
                    visited[i][j][k]=true;
                }
            }
        }
    }

    if(tomato==0) {
        cout << tomato;
        return 0;
    }
    while(!q.empty()) {
        int size = q.size();

        for(int i=0;i<size;i++) {
            int a = get<0>(q.front());
            int b = get<1>(q.front());
            int c = get<2>(q.front());
            q.pop();
            for(int i=0;i<6;i++) {
                int na = a +dx[i];
                int nb = b +dy[i];
                int nc = c +dz[i];
                if(na>=0 && nb >=0 && nc>=0 && H>na && N>nb && M>nc && !visited[na][nb][nc] && arr[na][nb][nc]==0) {
                    q.push({na,nb,nc});
                    visited[na][nb][nc]=visited[a][b][c]+1;
                    tomato--;
                }
            }
        }
        days++;
    }
    if(tomato>0) {
        cout <<-1;
    } else {
        cout <<days-1;
    }
}