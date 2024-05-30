#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

struct Node {
    int total, max_prefix, max_suffix, max_subarray;

    Node() : total(0), max_prefix(0), max_suffix(0), max_subarray(0) {}
    Node(int value) : total(value), max_prefix(value), max_suffix(value), max_subarray(value) {}
};

class SegmentTree {
public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 1, 0, n - 1);
    }

    Node query(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }

private:
    int n;
    vector<Node> tree;

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(data[start]);
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node, start, mid);
            build(data, 2 * node + 1, mid + 1, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    Node query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) {
            return Node(-1001);
        }
        if (left <= start && end <= right) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node left_child = query(2 * node, start, mid, left, right);
        Node right_child = query(2 * node + 1, mid + 1, end, left, right);
        return merge(left_child, right_child);
    }

    Node merge(const Node& left, const Node& right) {
        Node result;
        result.total = left.total + right.total;
        result.max_prefix = max(left.max_prefix, left.total + right.max_prefix);
        result.max_suffix = max(right.max_suffix, right.total + left.max_suffix);
        result.max_subarray = max({left.max_subarray, right.max_subarray, left.max_suffix + right.max_prefix});
        return result;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    SegmentTree segTree(A);

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int left, right;
        cin >> left >> right;
        --left; --right;
        Node result = segTree.query(left, right);
        cout << result.max_subarray << endl;
    }

    return 0;
}