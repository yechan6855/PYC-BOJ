#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class SegmentTree {
public:
    SegmentTree(int n) : n(n) {
        tree.resize(4 * n, 0);
    }

    void update(int idx, int val, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;

        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;

            if (idx <= mid) {
                update(idx, val, 2 * node, start, mid);
            } else {
                update(idx, val, 2 * node + 1, mid + 1, end);
            }
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int L, int R, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (R < start || end < L) return 0;
        if (L <= start && end <= R) return tree[node];

        int mid = (start + end) / 2;
        int left_query = query(L, R, 2 * node, start, mid);
        int right_query = query(L, R, 2 * node + 1, mid + 1, end);

        return max(left_query, right_query);
    }

private:
    int n;
    vector<int> tree;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        SegmentTree segTree(N);
        map<int, int> lastIndex;

        bool isWeird = true;

        for (int i = 0; i < N; ++i) {
            if (lastIndex.find(A[i]) != lastIndex.end()) {
                int lastIdx = lastIndex[A[i]];
                int maxInRange = segTree.query(lastIdx + 1, i - 1);

                if (maxInRange > A[i]) {
                    isWeird = false;
                    break;
                }
            }
            segTree.update(i, A[i]);
            lastIndex[A[i]] = i;
        }

        if (isWeird) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}