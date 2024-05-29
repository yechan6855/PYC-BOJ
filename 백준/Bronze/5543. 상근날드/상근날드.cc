#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    int a[3];
    int b[2];
    for(int i=0; i<3; i++){
        cin>>a[i];
    }
    sort(a,a+3);
    for(int i=0;i<2;i++){
        cin>>b[i];
    }
    sort(b,b+2);
    cout<<a[0]+b[0]-50;
}