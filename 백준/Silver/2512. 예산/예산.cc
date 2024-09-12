#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main() {
    int N, M;
    cin >> N;

    vector<int> solve(N);
    for (int i = 0; i < N; i++) {
        cin >> solve[i];
    }

    cin >> M;

    int l = 0;
    int r = *max_element(solve.begin(), solve.end());
    int ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        long long tot = 0;

        for (int b : solve) {
            tot += min(b, mid);
        }

        if (tot <= M) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}