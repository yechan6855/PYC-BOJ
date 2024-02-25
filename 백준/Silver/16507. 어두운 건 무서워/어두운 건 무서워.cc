#include <bits/stdc++.h>

using namespace std;

int R, C, Q;
int arr[1005][1005];
int dp[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> Q;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> arr[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }
    for(int i = 0; i < Q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1]) / ((r2-r1+1)*(c2-c1+1)) << '\n';
    }
}