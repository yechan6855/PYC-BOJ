#include <bits/stdc++.h>
#define ll long long
using namespace std;


int n, h[55][55], dx[8] = {1,1,1,0,-1,-1,-1,0}, dy[8] = {-1,0,1,1,1,0,-1,-1}, cnt, chk[55][55], ans = 1000011, st[2], chkcnt;
char mp[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> mp[i][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> h[i][j];
            if(mp[i][j] != '.') cnt++;
            if(mp[i][j] == 'P') st[0] = i, st[1] = j;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int l = 0, r = 1000000;
            while(l <= r){
                chkcnt++;
                int mid = (l + r) / 2, midn = 0;
                int mn = h[i][j], mx = h[i][j] + mid;
                if(h[st[0]][st[1]] < mn || mx < h[st[0]][st[1]]){
                    l = mid + 1;
                    continue;
                }
                queue<int> qx, qy;
                qx.push(st[0]), qy.push(st[1]);
                chk[st[0]][st[1]] = chkcnt;
                while(!qx.empty()){
                    int x = qx.front(), y = qy.front();
                    qx.pop(), qy.pop();
                    if(mp[x][y] != '.') midn++;
                    for(int k = 0; k < 8; k++){
                        int xx = x + dx[k], yy = y + dy[k];
                        if(1 <= xx && 1 <= yy && xx <= n && yy <= n && mn <= h[xx][yy] && h[xx][yy] <= mx && chk[xx][yy] != chkcnt){
                            qx.push(xx), qy.push(yy);
                            chk[xx][yy] = chkcnt;
                        }
                    }
                }
                if(midn < cnt) l = mid + 1;
                else r = mid - 1;
            }
            ans = min(ans, l);
        }
    }
    cout << ans;
    return 0;
}