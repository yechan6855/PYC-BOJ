#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int ans = 1;
    int j = 0;

    for(int i = 0; i < n; i++){
        while(j < n && arr[j] - arr[i] <= 4){
            j++;
        }

        int length = j - i;
        ans = max(ans, length);
    }

    if(ans >= 5) {
        cout << 0 << "\n";
    } else {
        cout << 5 - ans << "\n";
    }

    return 0;
}