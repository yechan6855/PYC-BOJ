#include <bits/stdc++.h>
using namespace std;

int convert(int x) {
    if (x == 0) return 0;
    return x > 0 ? 1 : -1;
}

class SegmentTree {
private:
    vector<int> tree;
    int size;

    int construct(const vector<int>& arr, int start, int end, int node) {
        if (start == end) return tree[node] = arr[start];

        int mid = (start + end) / 2;
        return tree[node] = construct(arr, start, mid, node * 2) * construct(arr, mid + 1, end, node * 2 + 1);
    }

    int update(int index, int val, int start, int end, int node) {
        if (index < start || index > end) return tree[node];
        if (start == end) return tree[node] = val;

        int mid = (start + end) / 2;
        return tree[node] = update(index, val, start, mid, node * 2) * update(index, val, mid + 1, end, node * 2 + 1);
    }

    int query(int left, int right, int start, int end, int node) {
        if (left > end || right < start) return 1;
        if (left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return query(left, right, start, mid, node * 2) * query(left, right, mid + 1, end, node * 2 + 1);
    }

public:
    SegmentTree(const vector<int>& arr) {
        size = arr.size();
        tree.resize(size * 4);
        construct(arr, 0, size - 1, 1);
    }

    void update(int index, int val) {
        update(index, val, 0, size - 1, 1);
    }

    int query(int left, int right) {
        return query(left, right, 0, size - 1, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    while (cin >> N >> K) {
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            arr[i] = convert(x);
        }

        SegmentTree st(arr);

        for (int i = 0; i < K; i++) {
            char op;
            int a, b;
            cin >> op >> a >> b;

            if (op == 'C') {
                st.update(a - 1, convert(b));
            } else if (op == 'P') {
                int res = st.query(a - 1, b - 1);
                cout << (res == 0 ? '0' : (res > 0 ? '+' : '-'));
            }
        }
        cout << "\n";
    }
    return 0;
}