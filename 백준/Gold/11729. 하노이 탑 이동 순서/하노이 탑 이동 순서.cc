#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<ll,ll>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void hanoi(ll n, ll f, ll t, ll v, vector<pi> &m) {
    if (n == 1) {
        m.pb({f, t});
        return;
    }
    hanoi(n - 1, f, v, t, m);
    m.pb({f, t});
    hanoi(n - 1, v, t, f, m);
}

int main() {
    io;
    ll N;
    cin >> N;

    vector<pi> m;
    hanoi(N, 1, 3, 2, m);

    cout << m.size() << endl;
    for (const auto &move : m) {
        cout << move.fi << " " << move.se << endl;
    }

    return 0;
}