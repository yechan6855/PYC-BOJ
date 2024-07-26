#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main(){
    io;
    ll t;
    cin>>t;
    for(int i=1; i<=t; i++){
        vector<int>ans(5);
        for(int j=0; j<5; j++){
            cin>>ans[j];
        }
        int max_ans= *max_element(ans.begin(),ans.end());
        cout<<"Case #"<<i<<": "<<max_ans<<endl;
    }
}