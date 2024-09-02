#include <bits/stdc++.h>
using namespace std;

string arr[10]={"ABCDEFGHJLM","ACEFGHILM","ACEFGHILM","ABCEFGHLM","ACEFGHLM","ACEFGHLM","ACEFGHLM","ACEFGHLM","ACEFGHLM","ABCFGHLM"};

int main(){
    int n;
    cin>>n;

    cout<<arr[n-1].size()<<endl;
    for(int i=0; i<arr[n-1].size(); i++){
        cout<<arr[n-1][i]<<" ";
    }
}