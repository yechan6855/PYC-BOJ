#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define di deque<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main()
{
    int n;
    cin>>n;
    int star=2*n-1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<i; ++j){
            cout<<" ";
        }
        for(int j=0; j<star-2*i; ++j){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=n-2; i>=0; --i){
        for(int j=0; j<i; ++j){
            cout<<" ";
        }
        for(int j=0; j<star-2*i; ++j){
            cout<<"*";
        }
        cout<<endl;
    }
}