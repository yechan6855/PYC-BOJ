#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int INF = 1e9 + 1;

class SegmentTree {
private:
    vector<int> tree;
    int size;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return INF;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_min = query(2 * node, start, mid, L, R);
        int right_min = query(2 * node + 1, mid + 1, end, L, R);
        return min(left_min, right_min);
    }

public:
    SegmentTree(const vector<int>& arr) {
        size = arr.size();
        tree.resize(4 * size);
        build(arr, 1, 0, size - 1);
    }

    void update(int idx, int val) {
        update(1, 0, size - 1, idx, val);
    }

    int query(int L, int R) {
        return query(1, 0, size - 1, L, R);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int a = 0; a < N; ++a) {
        cin >> arr[a];
    }

    SegmentTree segTree(arr);

    int M;
    cin >> M;
    for (int a = 0; a < M; ++a) {
        int type, i, j;
        cin >> type >> i >> j;
        if (type == 1) {
            segTree.update(i - 1, j);
        } else if (type == 2) {
            cout << segTree.query(i - 1, j - 1) << endl;
        }
    }

    return 0;
}