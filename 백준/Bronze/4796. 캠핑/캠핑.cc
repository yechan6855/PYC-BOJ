#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l,p,v;
    int caseN=1;

    while(true){
        cin>>l>>p>>v;

        if(l==0&&p==0&&v==0)break;

        int ans=(v/p)*l+min(v%p,l);

        cout<<"Case "<<caseN<<": "<<ans<<endl;
        caseN++;
    }
}