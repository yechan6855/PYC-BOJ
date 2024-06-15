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
#define MOD 9901
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAX_N = 50;

int n;
int b[MAX_N];
unordered_map<int, int> dp;

int main() {
    io;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> next_dp = dp;

        for (auto &[dif, height] : dp) {
            int diff = dif + b[i];
            next_dp[diff] = max(next_dp[diff], height);

            diff = abs(dif - b[i]);
            next_dp[diff] = max(next_dp[diff], height + min(dif, b[i]));
        }

        dp = move(next_dp);
    }

    if (dp[0] == 0) {
        cout << -1 << endl;
    } else {
        cout << dp[0] << endl;
    }

    return 0;
}