#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<"X";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}