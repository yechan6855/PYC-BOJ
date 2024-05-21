#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int INF = 1e9+1;

struct SegmentTree {
    int n;
    vector<int> tree, idx;

    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        idx.resize(4 * n);
        build(data, 1, 0, n - 1);
    }

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
            idx[node] = start;
        } else {
            int mid = (start + end) / 2;
            build(data, node * 2, start, mid);
            build(data, node * 2 + 1, mid + 1, end);
            if (tree[node * 2] <= tree[node * 2 + 1]) {
                tree[node] = tree[node * 2];
                idx[node] = idx[node * 2];
            } else {
                tree[node] = tree[node * 2 + 1];
                idx[node] = idx[node * 2 + 1];
            }
        }
    }

    void update(int pos, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] = value;
            idx[node] = start;
        } else {
            int mid = (start + end) / 2;
            if (pos <= mid) {
                update(pos, value, node * 2, start, mid);
            } else {
                update(pos, value, node * 2 + 1, mid + 1, end);
            }
            if (tree[node * 2] <= tree[node * 2 + 1]) {
                tree[node] = tree[node * 2];
                idx[node] = idx[node * 2];
            } else {
                tree[node] = tree[node * 2 + 1];
                idx[node] = idx[node * 2 + 1];
            }
        }
    }

    pair<int, int> query(int L, int R, int node, int start, int end) {
        if (R < start || end < L) return {INF, -1};
        if (L <= start && end <= R) return {tree[node], idx[node]};
        int mid = (start + end) / 2;
        pair<int, int> left = query(L, R, node * 2, start, mid);
        pair<int, int> right = query(L, R, node * 2 + 1, mid + 1, end);
        if (left.first <= right.first) return left;
        return right;
    }

    void update(int pos, int value) {
        update(pos, value, 1, 0, n - 1);
    }

    int query() {
        return idx[1] + 1;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    SegmentTree segTree(A);
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int index, value;
            cin >> index >> value;
            segTree.update(index - 1, value);
        } else if (type == 2) {
            cout << segTree.query() << endl;
        }
    }

    return 0;
}