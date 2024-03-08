#include <bits/stdc++.h>

using namespace std;

vector<long long> arr;
vector<long long> tree, lazy;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void updateLazy(int node, int start, int end, int left, int right, long long diff) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (end < left || start > right) return;

    if (left <= start && end <= right) {
        tree[node] += (end - start + 1) * diff;
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateLazy(node * 2, start, mid, left, right, diff);
    updateLazy(node * 2 + 1, mid + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (end < left || start > right) return 0;

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    arr.resize(N + 1);
    tree.resize(4 * (N + 1));
    lazy.resize(4 * (N + 1));

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    init(1, 1, N);

    for (int i = 0; i < M + K; ++i) {
        int op;
        cin >> op;

        if (op == 1) {
            int left, right;
            long long diff;
            cin >> left >> right >> diff;
            updateLazy(1, 1, N, left, right, diff);
        } else {
            int left, right;
            cin >> left >> right;
            cout << query(1, 1, N, left, right) << '\n';
        }
    }
    return 0;
}