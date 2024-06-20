#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

ll n, d;
ll ans = 0;

vector<ll> t(1010101);
vector<ll> v(1010101);

void solve(ll s, ll e, ll is, ll ie) {
    ll mid = (s + e) / 2;
    ll maxi = 0, id = 0;
    ll lo = max(mid, is);
    ll hi = min(mid + d, ie);

    for (ll i = lo; i <= hi; i++) {
        if ((i - mid) * t[i] + v[mid] > maxi) {
            maxi = (i - mid) * t[i] + v[mid];
            id = i;
        }
    }

    ans = max(ans, maxi);
    if (s != mid) solve(s, mid - 1, is, id);
    if (e != mid) solve(mid + 1, e, id, ie);
}

int main() {
    io;
    cin >> n >> d;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    solve(1, n, 1, n);
    cout << ans << endl;

    return 0;
}