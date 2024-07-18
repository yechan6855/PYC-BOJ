#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

ll kex(const vector<int>& A, ll k) {
    ll left = 0, right = 2e9;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        ll count = mid - (lower_bound(A.begin(), A.end(), mid) - A.begin());
        if (count >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    io;
    int n, q;
    cin >> n >> q;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        cout << kex(A, k)-1 << " ";
    }
    cout << endl;

    return 0;
}