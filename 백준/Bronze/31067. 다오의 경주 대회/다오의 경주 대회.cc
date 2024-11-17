#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    vector<ll> A(N);

    for(auto &x:A) cin>>x;
    if(N ==1){
        cout << 0;
        return 0;
    }

    ll prev_dp0 = 0;
    ll prev_dp1 = 1;
    for(int i=1;i<N;i++){
        ll current_dp0 = INF;
        ll current_dp1 = INF;

        if(A[i] > A[i-1]){
            current_dp0 = min(current_dp0, prev_dp0);
        }
        if(A[i] > A[i-1] + K){
            current_dp0 = min(current_dp0, prev_dp1);
        }
        if(A[i] + K > A[i-1]){
            current_dp1 = min(current_dp1, prev_dp0 +1);
        }
        if(A[i] + K > A[i-1] + K){
            current_dp1 = min(current_dp1, prev_dp1 +1);
        }
        prev_dp0 = current_dp0;
        prev_dp1 = current_dp1;
    }
    ll ans = min(prev_dp0, prev_dp1);
    if(ans >= INF){
        cout << "-1";
    }
    else{
        cout << ans;
    }
}