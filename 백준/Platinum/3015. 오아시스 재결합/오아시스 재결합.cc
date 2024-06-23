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

int32_t main() {
    io;
    int n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    stack<pii> s;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        int solve = arr[i];
        int cnt = 1;

        while (!s.empty() && s.top().fi <= solve) {
            ans += s.top().se;
            if (s.top().fi == solve) {
                cnt += s.top().se;
            }
            s.pop();
        }
        if (!s.empty()) {
            ans += 1;
        }
        s.push({solve, cnt});
    }
    cout << ans << endl;
}