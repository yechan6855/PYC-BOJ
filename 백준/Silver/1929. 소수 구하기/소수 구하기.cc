#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int m,n;

bool isPrime(int num){
    if(num==1) return false;
    for(int i=2; i*i<=num; i++){
        if(num%i==0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    for(int i=m; i<=n; i++){
        if(isPrime(i)){
            cout << i << endl;
        }
    }

    return 0;
}