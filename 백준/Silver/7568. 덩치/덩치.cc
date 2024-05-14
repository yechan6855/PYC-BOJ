#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define endl "\n"
#define pair pair<int,int>
using namespace std;
int32_t main() {
    int n;
    cin>>n;
    vector<pair>p(n);

    for(int i=0; i<n; ++i){
        cin>>p[i].fi>>p[i].se;
    }
    for(int i=0; i<n; ++i){
        int rank=1;
        for(int j=0; j<n; ++j){
            if(i!=j&&p[i].fi<p[j].fi&&p[i].se<p[j].se){
                rank++;
            }
        }
        cout<<rank<<" ";
    }
    cout<<endl;
}