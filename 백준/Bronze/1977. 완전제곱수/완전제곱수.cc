#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    vector<int> x;
    int result=0;
    cin>>n;
    cin>>m;
    for(int i=1; i<=m; i++){
        if(i*i>=n && i*i<=m){
            result+=(i*i);
            x.push_back(i*i);
        }
        if(i>m){
            break;
        }
    }
    sort(x.begin(),x.end());
    if(result!=0){
        cout<<result<<"\n"<<x[0];
    }else{
        cout<<-1;
    }
}