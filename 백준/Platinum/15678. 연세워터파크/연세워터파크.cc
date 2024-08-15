#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<ll> A(n + 1);
    vector<ll> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    deque<int> dq;

    ll ans = LLONG_MIN;

    for (int i = 1; i <= n; i++) {
        if (!dq.empty() && dq.front() < i - d) {
            dq.pop_front();
        }

        dp[i] = A[i];
        if (!dq.empty()) {
            dp[i] = max(dp[i], dp[dq.front()] + A[i]);
        }

        ans = max(ans, dp[i]);

        while (!dq.empty() && dp[dq.back()] <= dp[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << ans << "\n";

    return 0;
}