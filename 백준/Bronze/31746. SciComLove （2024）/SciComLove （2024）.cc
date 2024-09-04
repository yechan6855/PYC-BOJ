#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s="SciComLove";
    cin>>n;

    if(n%2==1){
        reverse(s.begin(),s.end());
        cout<<s;
    }else{
        cout<<s;
    }
}