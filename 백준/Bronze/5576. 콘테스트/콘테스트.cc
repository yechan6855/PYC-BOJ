#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w[10],k[10];

    for(int i=0;i<10;i++) {
        cin>>w[i];
    }
    for(int i=0;i<10;i++) {
        cin>>k[i];
    }

    sort(w,w+10);
    sort(k,k+10);

    cout<<w[7]+w[8]+w[9]<<endl;
    cout<<k[7]+k[8]+k[9]<<endl;
}