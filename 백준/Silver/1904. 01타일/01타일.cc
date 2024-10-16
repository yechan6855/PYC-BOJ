#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n == 1){
        cout << "1";
        return 0;
    }
    if(n == 2){
        cout << "2";
        return 0;
    }

    ll pr2 = 1;
    ll pr1 = 2;
    ll cur = 0;

    for(int i = 3; i <= n; ++i){
        cur = (pr1 + pr2) % 15746;
        pr2 = pr1;
        pr1 = cur;
    }

    cout << cur;
    return 0;
}