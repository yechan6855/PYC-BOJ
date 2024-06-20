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

class Rcali {
public:
    int pnum, chnum;
    vector<pair<ll, ll>> p, ch;

    Rcali(int _pnum) {
        pnum = _pnum;
        chnum = 0;
        p.reserve(pnum);
        ch.reserve(pnum);
    }

    int CCW(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
        ll val = (b.fi - a.fi) * (c.se - a.se) - (b.se - a.se) * (c.fi - a.fi);
        if (val > 0) return 1;
        else if (val == 0) return 0;
        return -1;
    }

    void GScan() {
        swap(p[0], *min_element(p.begin(), p.end()));
        sort(p.begin() + 1, p.end(), [&](pair<ll, ll> a, pair<ll, ll> b) {
            int ccw = CCW(p[0], a, b);
            if (ccw != 0) return ccw > 0;
            return a < b;
        });

        for (int i = 0; i < pnum; i++) {
            while (chnum > 1 && CCW(ch[chnum - 2], ch[chnum - 1], p[i]) <= 0) {
                chnum--;
                ch.pop_back();
            }
            if (chnum < ch.size()) {
                ch[chnum++] = p[i];
            } else {
                ch.pb(p[i]);
                chnum++;
            }
        }
        ch.resize(chnum);
    }

    pair<pair<ll, ll>, pair<ll, ll>> diameter() {
        GScan();
        ll mx = 0;
        pair<pair<ll, ll>, pair<ll, ll>> ans;

        for (int i = 0, j = 1; i < chnum; i++) {
            int inxt = (i + 1) % chnum;
            int jnxt = (j + 1) % chnum;
            while (CCW(ch[i], ch[inxt], {ch[i].fi + ch[jnxt].fi - ch[j].fi, ch[i].se + ch[jnxt].se - ch[j].se}) == 1) {
                j = jnxt;
                jnxt = (j + 1) % chnum;
            }
            ll dist = (ch[i].fi - ch[j].fi) * (ch[i].fi - ch[j].fi) + (ch[i].se - ch[j].se) * (ch[i].se - ch[j].se);
            if (mx < dist) {
                mx = dist;
                ans = {ch[i], ch[j]};
            }
        }
        return ans;
    }
};

int main() {
    io;
    int T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        Rcali rc(N);
        for (int i = 0; i < N; i++) {
            ll x, y;
            cin >> x >> y;
            rc.p.pb({x, y});
        }
        pair<pair<ll, ll>, pair<ll, ll>> ans = rc.diameter();
        cout << ans.fi.fi << " " << ans.fi.se << " " << ans.se.fi << " " << ans.se.se << endl;
    }
    return 0;
}