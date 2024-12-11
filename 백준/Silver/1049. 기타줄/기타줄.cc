#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    int p = INT_MAX;
    int s = INT_MAX;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        if(a < p){
            p = a;
        }
        if(b < s){
            s = b;
        }
    }
    
    ll c1 = (ll)N * s;
    
    int num = N / 6;
    int r = N % 6;
    
    ll c2 = (ll)num * p + (ll)r * s;
    ll c3 = ((ll)(num + 1)) * p;
    
    ll ans = min({c1, c2, c3});

    cout << ans;

    return 0;
}