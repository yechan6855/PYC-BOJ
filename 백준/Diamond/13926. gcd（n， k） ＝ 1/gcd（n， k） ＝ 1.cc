#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define di deque<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll mul(ll a, ll b, ll m) {
    ll r = 0;
    a %= m;
    while (b) {
        if (b & 1) r = (r + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return r;
}

ll pow(ll a, ll b, ll m) {
    ll r = 1;
    a %= m;
    while (b) {
        if (b & 1) r = mul(r, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return r;
}

bool miller_rabin(ll n, ll a) {
    if (n % a == 0) return false;
    ll d = n - 1;
    while (d % 2 == 0) {
        if (pow(a, d, n) == n-1) return true;
        d /= 2;
    }
    ll tmp = pow(a, d, n);
    return tmp == n-1 || tmp == 1;
}

bool is_prime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (!miller_rabin(n, a)) return false;
    }
    return true;
}

ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;
    ll x = rand() % (n - 2) + 2;
    ll y = x;
    ll c = rand() % (n - 1) + 1;
    ll d = 1;
    while (d == 1) {
        x = (mul(x, x, n) + c) % n;
        y = (mul(y, y, n) + c) % n;
        y = (mul(y, y, n) + c) % n;
        d = gcd(abs(x - y), n);
        if (d == n) return pollard_rho(n);
    }
    return d;
}

void solve(ll n, vector<ll>& factors) {
    if (n == 1) return;
    if (is_prime(n)) {
        factors.push_back(n);
        return;
    }
    ll d = pollard_rho(n);
    solve(d, factors);
    solve(n / d, factors);
}

int main() {
    io;
    srand(time(0));

    ll n;
    cin >> n;

    vector<ll> ans;
    solve(n, ans);

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    ll result = n;
    for (ll p : ans) {
        result = result / p * (p - 1);
    }

    cout << result << endl;

    return 0;
}