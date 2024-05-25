#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int MAX_N = 100000;
vector<int> tree[4 * MAX_N];
vector<int> arr;

void build(int node, int start, int end) {
    if (start == end) {
        tree[node].push_back(arr[start]);
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        merge(tree[2 * node].begin(), tree[2 * node].end(),
              tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
              back_inserter(tree[node]));
    }
}

int query(int node, int start, int end, int l, int r, int k) {
    if (start > r || end < l) {
        return 0;
    }
    if (start >= l && end <= r) {
        return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
    }
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r, k) + query(2 * node + 1, mid + 1, end, l, r, k);
}

int find_kth(int l, int r, int k, int n) {
    int low = -1e9, high = 1e9;
    while (low <= high) {
        int mid = (low + high) / 2;
        int count = query(1, 0, n - 1, l, r, mid);
        if (count >= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << find_kth(i - 1, j - 1, k, n) << endl;
    }

    return 0;
}