#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int32_t main() {
    int w, n;
    cin >> w >> n;
    vector<int> a(n);
    vector<int> cnt(800001, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cnt[a[i] + a[j]]++;
        }
    }

    bool isParcel = false;
    for (int i = 1; i < n - 2; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cnt[a[i] + a[j]]--;
        }

        for (int j = 0; j < i; ++j) {
            int result = w - a[j] - a[i];
            if (result >= 0 && cnt[result] > 0) {
                isParcel = true;
                break;
            }
        }
        if (isParcel){
            break;
        }
    }

    cout << (isParcel ? "YES" : "NO") << endl;
    return 0;
}