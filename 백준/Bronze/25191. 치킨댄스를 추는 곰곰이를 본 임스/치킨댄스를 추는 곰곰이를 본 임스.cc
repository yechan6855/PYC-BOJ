#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;

    if(a/2+b>n){
        cout<<n;
    }else{
        cout<<a/2+b;
    }
}