#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define endl "\n"
#define io ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct Bus {
    ll S, E, C;

    bool operator<(const Bus& other) const {
        if (S != other.S) return S < other.S;
        if (E != other.E) return E < other.E;
        return C < other.C;
    }
};

int main() {
    io;
    int n;
    cin >> n;

    vector<Bus> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].S >> arr[i].E >> arr[i].C;
    }

    sort(arr.begin(), arr.end());

    vector<Bus> ans;
    Bus cur = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i].S <= cur.E) {
            if (arr[i].C < cur.C) {
                cur.C = arr[i].C;
            }
            cur.E = max(cur.E, arr[i].E);
        } else {
            ans.pb(cur);
            cur = arr[i];
        }
    }
    ans.pb(cur);

    cout << ans.size() << endl;
    for (const auto& route : ans) {
        cout << route.S << ' ' << route.E << ' ' << route.C << endl;
    }

    return 0;
}