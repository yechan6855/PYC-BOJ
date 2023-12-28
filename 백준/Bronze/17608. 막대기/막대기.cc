#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int st[n];
    for(int i=0; i<n; i++){
        cin>>st[i];
    }
    int max=0;
    int count=0;
    for(int i=n-1; i>=0; i--){
        if(st[i]>max){
            count++;
            max=st[i];
        }
    }
    cout<<count;
}