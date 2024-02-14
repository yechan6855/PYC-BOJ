#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m;
vector<int> arr;
vector<pair<int, int>> tree;

pair<int, int> init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = {arr[start], arr[start]};
    } else {
        int mid = (start + end) / 2;
        pair<int, int> left = init(node * 2, start, mid);
        pair<int, int> right = init(node * 2 + 1, mid + 1, end);
        return tree[node] = {min(left.first, right.first), max(left.second, right.second)};
    }
}

pair<int, int> query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return {INF, -INF};
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    pair<int, int> lQuery = query(node * 2, start, mid, left, right);
    pair<int, int> rQuery = query(node * 2 + 1, mid + 1, end, left, right);
    return {min(lQuery.first, rQuery.first), max(lQuery.second, rQuery.second)};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    arr.resize(n);
    tree.resize(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> result = query(1, 0, n - 1, a - 1, b - 1);
        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}