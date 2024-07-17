#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef long long ll;
vector<ll> arr;

ll solve(int left, int right) {
    if (left == right) return arr[left] * arr[left];

    int mid = (left + right) / 2;
    ll result = max(solve(left, mid), solve(mid+1, right));

    int lo = mid, hi = mid+1;
    ll sum = arr[lo] + arr[hi];
    ll minVal = min(arr[lo], arr[hi]);
    result = max(result, sum * minVal);

    while (left < lo || hi < right) {
        if (hi < right && (lo == left || arr[lo-1] < arr[hi+1])) {
            hi++;
            sum += arr[hi];
            minVal = min(minVal, arr[hi]);
        } else {
            lo--;
            sum += arr[lo];
            minVal = min(minVal, arr[lo]);
        }
        result = max(result, sum * minVal);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << solve(0, N-1) << endl;

    return 0;
}