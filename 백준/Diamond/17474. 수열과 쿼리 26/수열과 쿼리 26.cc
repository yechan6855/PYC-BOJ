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
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int MAXN = 1000000;
const ll INF = 1LL << 60;
ll arr[MAXN + 1];
ll seg_max[4 * MAXN], seg_sum[4 * MAXN];
ll max2[4 * MAXN], lazy[4 * MAXN];
int count_max[4 * MAXN];

void build(int node, int start, int end) {
    lazy[node] = INF;
    if (start == end) {
        seg_max[node] = arr[start];
        seg_sum[node] = arr[start];
        count_max[node] = 1;
        max2[node] = -INF;
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        seg_max[node] = max(seg_max[2 * node], seg_max[2 * node + 1]);
        seg_sum[node] = seg_sum[2 * node] + seg_sum[2 * node + 1];
        if (seg_max[2 * node] == seg_max[2 * node + 1]) {
            count_max[node] = count_max[2 * node] + count_max[2 * node + 1];
            max2[node] = max(max2[2 * node], max2[2 * node + 1]);
        } else if (seg_max[2 * node] > seg_max[2 * node + 1]) {
            count_max[node] = count_max[2 * node];
            max2[node] = max(max2[2 * node], seg_max[2 * node + 1]);
        } else {
            count_max[node] = count_max[2 * node + 1];
            max2[node] = max(seg_max[2 * node], max2[2 * node + 1]);
        }
    }
}

void push(int node, int start, int end) {
    if (lazy[node] == INF) return;
    if (seg_max[node] <= lazy[node]) return;

    seg_sum[node] -= (seg_max[node] - lazy[node]) * count_max[node];
    seg_max[node] = lazy[node];
    if (start != end) {
        lazy[2 * node] = min(lazy[2 * node], lazy[node]);
        lazy[2 * node + 1] = min(lazy[2 * node + 1], lazy[node]);
    }
    lazy[node] = INF;
}

void update(int node, int start, int end, int l, int r, ll val) {
    push(node, start, end);
    if (start > r || end < l || seg_max[node] <= val) return;
    if (start >= l && end <= r && max2[node] < val) {
        lazy[node] = val;
        push(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);

    seg_max[node] = max(seg_max[2 * node], seg_max[2 * node + 1]);
    seg_sum[node] = seg_sum[2 * node] + seg_sum[2 * node + 1];
    if (seg_max[2 * node] == seg_max[2 * node + 1]) {
        count_max[node] = count_max[2 * node] + count_max[2 * node + 1];
        max2[node] = max(max2[2 * node], max2[2 * node + 1]);
    } else if (seg_max[2 * node] > seg_max[2 * node + 1]) {
        count_max[node] = count_max[2 * node];
        max2[node] = max(max2[2 * node], seg_max[2 * node + 1]);
    } else {
        count_max[node] = count_max[2 * node + 1];
        max2[node] = max(seg_max[2 * node], max2[2 * node + 1]);
    }
}

ll Max(int node, int start, int end, int l, int r) {
    push(node, start, end);
    if (start > r || end < l) return -INF;
    if (start >= l && end <= r) return seg_max[node];
    int mid = (start + end) / 2;
    return max(Max(2 * node, start, mid, l, r), Max(2 * node + 1, mid + 1, end, l, r));
}

ll Sum(int node, int start, int end, int l, int r) {
    push(node, start, end);
    if (start > r || end < l) return 0;
    if (start >= l && end <= r) return seg_sum[node];
    int mid = (start + end) / 2;
    return Sum(2 * node, start, mid, l, r) + Sum(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    io;
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    build(1, 1, n);

    cin >> m;
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            ll x;
            cin >> x;
            update(1, 1, n, l, r, x);
        } else if (type == 2) {
            cout << Max(1, 1, n, l, r) << endl;
        } else if (type == 3) {
            cout << Sum(1, 1, n, l, r) << endl;
        }
    }

    return 0;
}