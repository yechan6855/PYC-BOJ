#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n;
    cin>>n;

    for(int i=1; i<=n.size(); i++){
        cout<<n[i-1];
        if(i%10==0){
            cout<<"\n";
        }
    }
}