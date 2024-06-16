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

int n, m;
vvi dp;

int solve(int pos, int bitmask) {
    if (pos == n * m && bitmask == 0)
        return 1;
    if (pos >= n * m)
        return 0;
    if (dp[pos][bitmask] != -1)
        return dp[pos][bitmask];

    int &res = dp[pos][bitmask];
    res = 0;

    if (bitmask & 1) {
        res = solve(pos + 1, bitmask >> 1);
    } else {
        res = solve(pos + 1, (bitmask >> 1) | (1 << (m - 1)));
        if (pos % m != (m - 1) && !(bitmask & 2)) {
            res += solve(pos + 2, bitmask >> 2);
        }
    }

    return res %= MOD;
}

int main() {
    io;
    cin >> n >> m;
    dp.assign(n * m, vi(1 << m, -1));
    cout << solve(0, 0) << endl;
    return 0;
}