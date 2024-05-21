#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int size;

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] += value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, L, R) + query(2 * node + 2, mid + 1, end, L, R);
    }

public:
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void update(int idx, int value) {
        update(0, 0, size - 1, idx, value);
    }

    int query(int L, int R) {
        return query(0, 0, size - 1, L, R);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> position(n + 1);
        SegmentTree segTree(n + m);

        for (int i = 1; i <= n; ++i) {
            position[i] = m + i - 1;
            segTree.update(position[i], 1);
        }

        int currentTop = m - 1;
        for (int i = 0; i < m; ++i) {
            int movie;
            cin >> movie;

            int moviesAbove = segTree.query(0, position[movie] - 1);
            cout << moviesAbove << " ";

            segTree.update(position[movie], -1);
            position[movie] = currentTop--;
            segTree.update(position[movie], 1);
        }
        cout << '\n';
    }

    return 0;
}