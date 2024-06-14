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

vector<ll> arr, segTree, lazy;
int n, m, k;

void update_range(int node, int start, int end, int l, int r, ll val) {
    if (lazy[node] != 0) {
        segTree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > end || start > r || end < l)
        return;

    if (start >= l && end <= r) {
        segTree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    update_range(node*2, start, mid, l, r, val);
    update_range(node*2+1, mid+1, end, l, r, val);
    segTree[node] = segTree[node*2] + segTree[node*2+1];
}

ll query_range(int node, int start, int end, int l, int r) {
    if (start > end || start > r || end < l)
        return 0;

    if (lazy[node] != 0) {
        segTree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start >= l && end <= r)
        return segTree[node];

    int mid = (start + end) / 2;
    ll p1 = query_range(node*2, start, mid, l, r);
    ll p2 = query_range(node*2+1, mid+1, end, l, r);
    return p1 + p2;
}

void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(node*2, start, mid);
        build(node*2+1, mid+1, end);
        segTree[node] = segTree[node*2] + segTree[node*2+1];
    }
}

int main() {
    io;
    cin >> n >> m >> k;
    arr.resize(n);
    segTree.resize(4*n);
    lazy.resize(4*n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n-1);

    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        ll d;
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> d;
            update_range(1, 0, n-1, b-1, c-1, d);
        } else if (a == 2) {
            cout << query_range(1, 0, n-1, b-1, c-1) << endl;
        }
    }

    return 0;
}