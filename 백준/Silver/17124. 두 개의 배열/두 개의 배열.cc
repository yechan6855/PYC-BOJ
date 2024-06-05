#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define endl "\n"
#define elif else if
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int parametric(const vi& B, int value) {
    int left = 0, right = B.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (B[mid] == value) {
            return B[mid];
        } elif (B[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    if (left > 0 && abs(B[left] - value) >= abs(B[left - 1] - value)) {
        return B[left - 1];
    }
    return B[left];
}

int32_t main() {
    io;
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vi A(n);
        vi B(m);

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        for (int i = 0; i < m; ++i) {
            cin >> B[i];
        }

        sort(B.begin(), B.end());

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int search = parametric(B, A[i]);
            sum += search;
        }

        cout<<sum<<endl;
    }

    return 0;
}