#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

class MergeSortTree {
private:
    vector<vector<int>> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = vector<int>(1, arr[start]);
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
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
        }
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r, k) + query(2 * node + 1, mid + 1, end, l, r, k);
    }

public:
    MergeSortTree(const vector<int>& inputArr) {
        arr = inputArr;
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int query(int l, int r, int k) {
        return query(1, 0, n - 1, l, r, k);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    MergeSortTree mst(arr);

    int m;
    cin >> m;
    for (int q = 0; q < m; ++q) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << mst.query(i - 1, j - 1, k) << endl;
    }

    return 0;
}