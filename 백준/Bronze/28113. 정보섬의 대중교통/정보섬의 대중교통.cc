#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    if(b>a){
        cout<<"Bus"<<endl;
    }else if(b<a){
        cout<<"Subway"<<endl;
    }
    else{
        cout<<"Anything"<<endl;
    }
}