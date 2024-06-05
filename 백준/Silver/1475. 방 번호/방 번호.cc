#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int32_t main() {
    io;
    string N;
    cin >> N;

    vi c(10, 0);

    for (char s : N) {
        c[s - '0']++;
    }

    int solve = c[6] + c[9];
    c[6] = (solve + 1) / 2;
    c[9] = 0;

    int ans = *max_element(c.begin(), c.end());

    cout << ans << endl;
    return 0;
}