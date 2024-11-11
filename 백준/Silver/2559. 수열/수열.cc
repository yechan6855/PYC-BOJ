#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    vector<int> temp(n);
    for(int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    int sum = 0;

    for(int i = 0; i < k; i++) {
        sum += temp[i];
    }

    int ans = sum;

    for(int i = k; i < n; i++) {
        sum = sum - temp[i-k] + temp[i];
        ans = max(ans, sum);
    }

    cout << ans << '\n';

    return 0;
}