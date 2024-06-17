#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAXN = 200000;
const ll INF = 1e18;

struct SegmentTree {
    int n;
    vector<ll> min_tree, sum_tree;

    SegmentTree(int size) {
        n = size;
        min_tree.resize(2 * n, INF);
        sum_tree.resize(2 * n, 0);
    }

    void build() {
        for (int i = n - 1; i > 0; --i) {
            min_tree[i] = min(min_tree[i << 1], min_tree[i << 1 | 1]);
            sum_tree[i] = sum_tree[i << 1] + sum_tree[i << 1 | 1];
        }
    }

    void update(int p, ll value) {
        p += n;
        min_tree[p] = value;
        sum_tree[p] = value;
        for (; p > 1; p >>= 1) {
            min_tree[p >> 1] = min(min_tree[p], min_tree[p ^ 1]);
            sum_tree[p >> 1] = sum_tree[p] + sum_tree[p ^ 1];
        }
    }

    ll range_min(int l, int r) {
        ll res = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, min_tree[l++]);
            if (r & 1) res = min(res, min_tree[--r]);
        }
        return res;
    }

    ll range_sum(int l, int r) {
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += sum_tree[l++];
            if (r & 1) res += sum_tree[--r];
        }
        return res;
    }
};

int main() {
    io
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    SegmentTree segTree(n);
    for (int i = 0; i < n; ++i) {
        segTree.min_tree[i + n] = a[i];
        segTree.sum_tree[i + n] = a[i];
    }
    segTree.build();

    int m;
    cin >> m;

    while (m--) {
        int type, i, j;
        cin >> type >> i >> j;
        --i;

        if (type == 1) {
            segTree.update(i, j);
        } else if (type == 2) {
            int l = i, r = i;
            int low = 0, high = i;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (segTree.range_min(mid, i + 1) >= j) {
                    l = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            low = i, high = n - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (segTree.range_min(i, mid + 1) >= j) {
                    r = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            cout << segTree.range_sum(l, r + 1) << endl;
        }
    }

    return 0;
}