#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp_left(n), dp_right(n);

    dp_left[0] = arr[0];
    int max_sum = dp_left[0];
    for (int i = 1; i < n; i++) {
        dp_left[i] = max(arr[i], dp_left[i-1] + arr[i]);
        max_sum = max(max_sum, dp_left[i]);
    }

    dp_right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        dp_right[i] = max(arr[i], dp_right[i+1] + arr[i]);
    }

    for (int i = 1; i < n-1; i++) {
        int sum = dp_left[i-1] + dp_right[i+1];
        max_sum = max(max_sum, sum);
    }

    cout << max_sum << '\n';

    return 0;
}