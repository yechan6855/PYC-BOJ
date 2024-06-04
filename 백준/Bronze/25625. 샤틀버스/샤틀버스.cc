#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
int main() {
    io;
    int x,y;
    cin>>x>>y;
    int ans=(x>y)?(x+y):(y-x);
    cout<<ans;
    return 0;
}