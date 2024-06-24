#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

signed main() {
    int N;
    string S;
    cin >> N >> S;

    vi p;
    for (int i = 0; i < N; ++i) {
        if (S[i] != 'F') {
            p.pb(i);
        }
    }

    if (p.empty()) {
        cout << N << endl;
        for (int i = 0; i < N; ++i) {
            cout << i << endl;
        }
        return 0;
    }

    int mn = 0, mx = 0;
    for (size_t i = 0; i < p.size() - 1; ++i) {
        if (S[p[i]] == S[p[i + 1]]) {
            if (!((p[i + 1] - p[i] - 1) & 1)) {
                mn += 1;
            }
            mx += p[i + 1] - p[i];
        } else {
            if ((p[i + 1] - p[i] - 1) & 1) {
                mn += 1;
            }
            mx += p[i + 1] - p[i] - 1;
        }
    }

    vi ans;

    if (p[0] != 0 || p.back() != N - 1) {
        mx += p[0] + (N - 1 - p.back());
        for (int i = mn; i <= mx; ++i) {
            ans.pb(i);
        }
    } else {
        for (int i = mn; i <= mx; i += 2) {
            ans.pb(i);
        }
    }

    cout << ans.size() << endl;
    for (const int &x : ans) {
        cout << x << endl;
    }

    return 0;
}