#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, S;
    cin >> N >> S;

    if(N ==1){
        if(S ==0){
            cout << 1;
        }
        else{
            cout << 0;
        }
        return 0;
    }
    if(N ==2){
        if(S ==0){
            cout <<1;
        }
        else{
            cout <<0;
        }
        return 0;
    }

    vector<vector<vector<bool>>> dp(N+1, vector<vector<bool>>(2*(N-1)+1, vector<bool>(S+1, false)));
    dp[0][0][0] = true;

    for(int i=0; i<N; ++i){
        for(int d=0; d<=2*(N-1); ++d){
            for(int s=0; s<=S; ++s){
                if(dp[i][d][s]){
                    int remaining_nodes = N - i -1;
                    int max_degree = min(N-1, 2*(N-1) - d - remaining_nodes);
                    for(int degree=1; degree<=max_degree; ++degree){
                        int new_d = d + degree;
                        if(new_d > 2*(N-1)) continue;
                        int new_s = s + (degree*(degree-1))/2;
                        if(new_s > S) continue;
                        dp[i+1][new_d][new_s] = true;
                    }
                }
            }
        }
    }

    if(dp[N][2*(N-1)][S]){
        cout << 1;
    }
    else{
        cout << 0;
    }
}