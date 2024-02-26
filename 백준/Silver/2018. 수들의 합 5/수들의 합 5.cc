#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    int count=1;
    int s_index=1;
    int e_index=1;
    int sum=1;

    while(e_index!=n){
        if(sum==n){
            count++;
            e_index++;
            sum+=e_index;
        }else if(sum>n){
            sum-=s_index;
            s_index++;
        }else{
            e_index++;
            sum+=e_index;
        }
    }
    cout<<count<<endl;
}