#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,l;
    cin>>n>>l;

    int arr[n];

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    for(int i=0; i<n; i++) {
        if(arr[i]<=l) {
            l++;
        }
    }
    cout<<l<<endl;
}