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

void solve() {
    vector<ll> prime;
    int limit = static_cast<int>(sqrt(2e9)) + 1;
    vector<bool> isPrime(limit, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < limit; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < limit; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = 2; i < limit; ++i) {
        if (isPrime[i]) prime.pb(i);
    }

    class Square {
    public:
        ll getNum(ll x, const vector<ll>& prime) {
            queue<tuple<int, int, ll>> q;
            for (int i = 0; i < prime.size(); ++i) {
                ll e = prime[i];
                if (e * e > x) break;
                q.push({1, i, e});
            }

            ll ans = 0;
            while (!q.empty()) {
                auto [fcnt, fidx, fn] = q.front();
                q.pop();

                ans += (fcnt % 2 == 1 ? 1LL : -1LL) * (x / (fn * fn));

                for (int i = fidx + 1; i < prime.size(); ++i) {
                    ll e = prime[i];
                    if (fn * e * fn * e > x) break;
                    if (fn % e == 0) continue;
                    q.push({fcnt + 1, i, fn * e});
                }
            }
            return x - ans;
        }
    };

    Square cnt;

    ll lo = 0;
    ll hi = static_cast<ll>(2e9);

    ll K;
    cin >> K;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (cnt.getNum(mid, prime) < K) lo = mid;
        else hi = mid;
    }
    cout << hi << endl;
}

int main() {
    io;
    solve();
    return 0;
}