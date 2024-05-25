#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

class SegmentTree {
private:
    vector<ll> tree;
    vector<ll> arr;
    int size;

    ll build(int node, int start, int end) {
        if (start == end) {
            return tree[node] = arr[start];
        }
        int mid = (start + end) / 2;
        ll left_sum = build(2 * node, start, mid);
        ll right_sum = build(2 * node + 1, mid + 1, end);
        return tree[node] = left_sum + right_sum;
    }

    ll query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        ll left_sum = query(2 * node, start, mid, L, R);
        ll right_sum = query(2 * node + 1, mid + 1, end, L, R);
        return left_sum + right_sum;
    }

    void update(int node, int start, int end, int idx, ll value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, value);
            } else {
                update(2 * node + 1, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

public:
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n);
        arr.resize(n + 1);
    }

    void build() {
        build(1, 1, size);
    }

    ll query(int L, int R) {
        if (L > R) {
            swap(L, R);
        }
        return query(1, 1, size, L, R);
    }

    void update(int idx, ll value) {
        update(1, 1, size, idx, value);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    SegmentTree segTree(N);

    for (int i = 0; i < M; ++i) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 0) {
            cout << segTree.query(x, y) << endl;
        } else if (cmd == 1) {
            segTree.update(x, y);
        }
    }

    return 0;
}