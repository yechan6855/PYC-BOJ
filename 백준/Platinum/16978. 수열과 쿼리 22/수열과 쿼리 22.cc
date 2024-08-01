#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 100001;

int N, M;
ll arr[MAX], tree[MAX * 4];
vector<pair<int, pair<int, ll>>> query1;
vector<pair<int, pair<int, pair<int, int>>>> query2;
vector<ll> ans;

void update(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

ll sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(1, 1, N, i, arr[i]);
    }

    cin >> M;
    int q2_count = 0;
    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            ll v;
            cin >> k >> v;
            query1.push_back({k, {v, i}});
        } else {
            int k, l, r;
            cin >> k >> l >> r;
            query2.push_back({k, {q2_count, {l, r}}});
            q2_count++;
        }
    }

    sort(query2.begin(), query2.end());
    ans.resize(q2_count);

    int q1_idx = 0;
    for (auto& q : query2) {
        while (q1_idx < q.fi) {
            auto& upd = query1[q1_idx];
            ll diff = upd.se.fi - arr[upd.fi];
            arr[upd.fi] = upd.se.fi;
            update(1, 1, N, upd.fi, diff);
            q1_idx++;
        }
        ans[q.se.fi] = sum(1, 1, N, q.se.se.fi, q.se.se.se);
    }

    for (ll x : ans) cout << x << '\n';

    return 0;
}