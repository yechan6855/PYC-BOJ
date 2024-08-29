#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 100001;
const int MAX_A = 1000001;

int n, t, sq;
int arr[MAX_N];
int cnt[MAX_A];
ll ans[MAX_N], sum;

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        if (l / sq != other.l / sq) return l < other.l;
        return r < other.r;
    }
};

vector<Query> q;

void add(int x) {
    sum -= (ll)cnt[x] * cnt[x] * x;
    cnt[x]++;
    sum += (ll)cnt[x] * cnt[x] * x;
}

void remove(int x) {
    sum -= (ll)cnt[x] * cnt[x] * x;
    cnt[x]--;
    sum += (ll)cnt[x] * cnt[x] * x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sq = sqrt(n);

    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        q.push_back({l, r, i});
    }

    sort(q.begin(), q.end());

    int l = 1, r = 0;
    for (const auto &q : q) {
        while (l > q.l) add(arr[--l]);
        while (r < q.r) add(arr[++r]);
        while (l < q.l) remove(arr[l++]);
        while (r > q.r) remove(arr[r--]);
        ans[q.idx] = sum;
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}