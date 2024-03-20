#include <bits/stdc++.h>
#define ll long long
#define MAX LLONG_MAX

using namespace std;

int main()
{
    int n,car;
    int cnt=0;
    cin>>n;
    for(int i=0; i<5; i++){
        cin>>car;
        if(car%10==n){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}