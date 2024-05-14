#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int32_t main() {
    int k, n;
    cin >> k >> n;
    vector<int> lengths(k);

    for (int i = 0; i < k; ++i) {
        cin >> lengths[i];
    }
    int left = 1, right = *max_element(lengths.begin(), lengths.end());
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;

        for (int i = 0; i < k; ++i) {
            cnt += lengths[i] / mid;
        }

        if (cnt >= n) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result << endl;
}