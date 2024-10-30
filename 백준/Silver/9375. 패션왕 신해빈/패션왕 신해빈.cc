#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        map<string, int> arr;
        string a, b;

        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            arr[b]++;
        }

        ll ans = 1;
        for(auto it : arr) {
            ans *= (it.second + 1);
        }

        ans--;

        cout << ans << '\n';
    }

    return 0;
}