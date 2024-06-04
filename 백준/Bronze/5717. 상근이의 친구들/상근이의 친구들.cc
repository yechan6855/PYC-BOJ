#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
int main() {
    io;
    int x,y;
    while(1){
        cin>>x>>y;
        if(x==0 && y==0){
            break;
        }
        cout<<x+y<<endl;
    }
}