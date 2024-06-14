#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pi pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

ll mrg_cnt(vi& a, int l, int m, int r) {
    vi L(a.begin() + l, a.begin() + m + 1);
    vi R(a.begin() + m + 1, a.begin() + r + 1);

    int i = 0, j = 0, k = l;
    ll cnt = 0;

    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
            cnt += L.size() - i;
        }
    }

    while (i < L.size()) {
        a[k++] = L[i++];
    }

    while (j < R.size()) {
        a[k++] = R[j++];
    }

    return cnt;
}

ll mrg_srt_cnt(vi& a, int l, int r) {
    ll cnt = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        cnt += mrg_srt_cnt(a, l, m);
        cnt += mrg_srt_cnt(a, m + 1, r);

        cnt += mrg_cnt(a, l, m, r);
    }
    return cnt;
}

int main() {
    io;
    int n;
    cin >> n;
    vi a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << mrg_srt_cnt(a, 0, n - 1) << endl;

    return 0;
}