#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k,d,a;
    scanf("%d/%d/%d",&k,&d,&a);
    if(k+a<d || d==0){
        cout<<"hasu";
    }else{
        cout<<"gosu";
    }
}