#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

class SegmentTree {
public:
    SegmentTree(int n) : n(n) {
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int idx, int value) {
        update(1, 0, n - 1, idx, value);
    }

    int query(int k) {
        return query(1, 0, n - 1, k);
    }

private:
    int n;
    vector<int> tree;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 1;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int value) {
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

    int query(int node, int start, int end, int k) {
        if (start == end) {
            return start;
        }
        int mid = (start + end) / 2;
        if (tree[2 * node] >= k) {
            return query(2 * node, start, mid, k);
        } else {
            return query(2 * node + 1, mid + 1, end, k - tree[2 * node]);
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    SegmentTree segTree(N);
    vector<int> result;
    int current_pos = 0;

    for (int i = 0; i < N; ++i) {
        int remaining = N - i;
        current_pos = (current_pos + K - 1) % remaining;
        int person = segTree.query(current_pos + 1);
        result.push_back(person + 1);
        segTree.update(person, 0);
    }

    cout << "<";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">" << endl;

    return 0;
}