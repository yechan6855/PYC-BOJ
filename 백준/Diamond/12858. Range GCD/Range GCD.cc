#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pi pair<ll, ll>
#define mi map<ll, ll>
#define qi queue<ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define tiii tuple<ll,ll,ll>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAXN = 100000;

int N, Q;
vi A(MAXN + 1);
vi segTreeA(4 * MAXN);
vi segTreeD(4 * MAXN);
vi lazyA(4 * MAXN, 0);
vi lazyD(4 * MAXN, 0);

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void buildTree(vi& segTree, vi& arr, int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(segTree, arr, 2 * node, start, mid);
        buildTree(segTree, arr, 2 * node + 1, mid + 1, end);
        segTree[node] = gcd(segTree[2 * node], segTree[2 * node + 1]);
    }
}

void propagate(vi& segTree, vi& lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        segTree[node] += lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void rangeUpdate(vi& segTree, vi& lazy, int node, int start, int end, int l, int r, ll val) {
    propagate(segTree, lazy, node, start, end);
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        lazy[node] += val;
        propagate(segTree, lazy, node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    rangeUpdate(segTree, lazy, 2 * node, start, mid, l, r, val);
    rangeUpdate(segTree, lazy, 2 * node + 1, mid + 1, end, l, r, val);
    segTree[node] = gcd(segTree[2 * node], segTree[2 * node + 1]);
}

ll rangeQuery(vi& segTree, vi& lazy, int node, int start, int end, int l, int r) {
    propagate(segTree, lazy, node, start, end);
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return segTree[node];
    int mid = (start + end) / 2;
    ll leftGCD = rangeQuery(segTree, lazy, 2 * node, start, mid, l, r);
    ll rightGCD = rangeQuery(segTree, lazy, 2 * node + 1, mid + 1, end, l, r);
    return gcd(leftGCD, rightGCD);
}

int main() {
    io;

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vi D(N);
    for (int i = 1; i < N; ++i) {
        D[i] = A[i + 1] - A[i];
    }

    buildTree(segTreeA, A, 1, 1, N);
    buildTree(segTreeD, D, 1, 1, N - 1);

    cin >> Q;
    while (Q--) {
        int T, A, B;
        cin >> T >> A >> B;
        if (T == 0) {
            if (A == B) {
                cout << abs(rangeQuery(segTreeA, lazyA, 1, 1, N, A, A)) << endl;
            } else {
                ll g1 = rangeQuery(segTreeA, lazyA, 1, 1, N, A, A);
                ll g2 = rangeQuery(segTreeD, lazyD, 1, 1, N - 1, A, B - 1);
                cout << abs(gcd(g1, g2)) << endl;
            }
        } else {
            rangeUpdate(segTreeA, lazyA, 1, 1, N, A, B, T);
            if (A > 1) {
                rangeUpdate(segTreeD, lazyD, 1, 1, N - 1, A - 1, A - 1, T);
            }
            if (B < N) {
                rangeUpdate(segTreeD, lazyD, 1, 1, N - 1, B, B, -T);
            }
        }
    }

    return 0;
}