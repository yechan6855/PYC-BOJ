#include <bits/stdc++.h>

using namespace std;

const int MAX = INT_MAX;

struct SegmentTree {
    vector<int> tree;
    vector<int> arr;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n);
        arr.resize(n);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = start;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = (arr[tree[2 * node]] <= arr[tree[2 * node + 1]]) ? tree[2 * node] : tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = (arr[tree[2 * node]] <= arr[tree[2 * node + 1]]) ? tree[2 * node] : tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return -1;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_query = query(2 * node, start, mid, l, r);
        int right_query = query(2 * node + 1, mid + 1, end, l, r);

        if (left_query == -1) return right_query;
        if (right_query == -1) return left_query;
        return (arr[left_query] <= arr[right_query]) ? left_query : right_query;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N;
    SegmentTree st(N);
    for (int i = 0; i < N; i++) {
        cin >> st.arr[i];
    }
    st.build(1, 0, N - 1);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            st.update(1, 0, N - 1, a - 1, b);
        } else {
            cout << st.query(1, 0, N - 1, a - 1, b - 1) + 1 << "\n";
        }
    }
    return 0;
}