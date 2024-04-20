#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);

    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    for(int i=0; i<m; ++i){
        cin>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int diff=0;

    for(int i=0; i<n; ++i){
        if(!binary_search(b.begin(),b.end(),a[i])){
            diff++;
        }
    }
    for(int i=0; i<m; ++i){
        if(!binary_search(a.begin(),a.end(),b[i])){
            diff++;
        }
    }
    cout<<diff<<endl;
}