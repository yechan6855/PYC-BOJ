#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    io;
    int n;
    cin >> n;

    vi dp(32,0);

    dp[0] = 1;
    dp[1] = 0;
    if (n >= 2) {
        dp[2] = 3;
    }

    for (int i = 3; i <= n; ++i) {
        if (i % 2 == 0) {
            dp[i] = dp[i-2] * 3;
            for (int j = i-4; j >= 0; j -= 2) {
                dp[i] += dp[j] * 2;
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}