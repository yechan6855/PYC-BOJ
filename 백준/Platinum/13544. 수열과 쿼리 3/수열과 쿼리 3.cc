#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

class MergeSortTree {
public:
    MergeSortTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 0, 0, n - 1);
    }

    int query(int left, int right, int k) {
        return query(0, 0, n - 1, left, right, k);
    }

private:
    int n;
    vector<vector<int>> tree;

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node].push_back(data[start]);
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
                  tree[2 * node + 2].begin(), tree[2 * node + 2].end(),
                  back_inserter(tree[node]));
        }
    }

    int query(int node, int start, int end, int left, int right, int k) {
        if (right < start || end < left) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
        }
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, left, right, k) +
               query(2 * node + 2, mid + 1, end, left, right, k);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    MergeSortTree tree(data);

    int m;
    cin >> m;

    int last_ans = 0;
    for (int q = 0; q < m; ++q) {
        int a, b, c;
        cin >> a >> b >> c;
        int i = a ^ last_ans;
        int j = b ^ last_ans;
        int k = c ^ last_ans;
        if (i > j) swap(i, j);
        --i;
        --j;
        last_ans = tree.query(i, j, k);
        cout << last_ans << endl;
    }

    return 0;
}