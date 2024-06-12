#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pi pair<ll, ll>
#define mi map<ll, ll>
#define qi queue<ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define tiii tuple<ll,ll,ll>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    io;
    ll sum=0, val=0;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        switch(n){
            int x;
            case 1:
                cin>>x;
                sum+=x;
                val ^= x;
                break;
            case 2:
                cin>>x;
                sum-=x;
                val ^= x;
                break;
            case 3:
                cout<<sum<<endl;
                break;
            case 4:
                cout<<val<<endl;
                break;
        }
    }
}