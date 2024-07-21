#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1000001;

struct Node {
    int length;
    long long count;
    Node(int l = 0, long long c = 0) : length(l), count(c) {}
};

Node combine(Node left, Node right) {
    if (left.length > right.length) return left;
    if (left.length < right.length) return right;
    return Node(left.length, (left.count + right.count) % MOD);
}

vector<Node> tree(4 * MAX_N);

void update(int node, int start, int end, int idx, Node value) {
    if (idx < start || idx > end) return;
    if (start == end) {
        tree[node] = combine(tree[node], value);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, value);
    update(node * 2 + 1, mid + 1, end, idx, value);
    tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return Node();
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return combine(query(node * 2, start, mid, left, right),
                   query(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
    io;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> compressed(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        compressed[i] = a[i];
    }

    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(compressed.begin(), compressed.end(), a[i]) - compressed.begin() + 1;
        Node prev = query(1, 1, MAX_N, 1, idx - 1);
        Node current(prev.length + 1, max(1LL, prev.count));
        update(1, 1, MAX_N, idx, current);
    }

    Node result = tree[1];
    cout << result.length << " " << result.count << endl;

    return 0;
}