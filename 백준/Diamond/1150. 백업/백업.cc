#include <bits/stdc++.h>
#define endl "\n"
#define MAXN 100001
#define io ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int c[MAXN];
int npos[MAXN];
int last[MAXN];
int l, r, pos, val, sol, ans;

struct compare {
    bool operator()(const int &i, const int &j) const {
        return c[i] != c[j] ? c[i] < c[j] : i < j;
    }
};

set<int, compare> s;

int main() {
    int n, k;
    io;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (i) {
            c[i] = val - sol;
            s.insert(i);
            npos[i] = i + 1;
            last[i] = i - 1;
        }
        sol = val;
    }

    npos[n - 1] = last[1] = 0;

    for (int i = 0; i < k; i++) {
        pos = *s.begin();

        l = last[pos];
        r = npos[pos];

        s.erase(pos);

        if (l) {
            s.erase(l);
        }

        if (r) {
            s.erase(r);
        }

        ans += c[pos];
        c[pos] = c[l] + c[r] - c[pos];

        if (l && r) {
            s.insert(pos);
            last[pos] = last[l];
            npos[pos] = npos[r];
        } else {
            pos = 0;
        }

        if (last[l]) {
            npos[last[l]] = pos;
        }

        if (npos[r]) {
            last[npos[r]] = pos;
        }
    }

    cout << ans << endl;

    return 0;
}