#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAX = 2000000;

class SegmentTree {
public:
    SegmentTree(int n) : n(n) {
        tree.resize(4 * n, 0);
    }

    void update(int pos, int val, int node = 1, int start = 0, int end = MAX) {
        if (start == end) {
            tree[node] += val;
        } else {
            int mid = (start + end) / 2;
            if (pos <= mid) {
                update(pos, val, 2 * node, start, mid);
            } else {
                update(pos, val, 2 * node + 1, mid + 1, end);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int k, int node = 1, int start = 0, int end = MAX) {
        if (start == end) {
            return start;
        }
        int mid = (start + end) / 2;
        if (tree[2 * node] >= k) {
            return query(k, 2 * node, start, mid);
        } else {
            return query(k - tree[2 * node], 2 * node + 1, mid + 1, end);
        }
    }

private:
    vi tree;
    int n;
};

int main() {
    io;
    int N;
    cin >> N;

    SegmentTree segTree(MAX + 1);

    for (int i = 0; i < N; ++i) {
        int T, X;
        cin >> T >> X;
        if (T == 1) {
            segTree.update(X, 1);
        } else if (T == 2) {
            int result = segTree.query(X);
            cout << result << endl;
            segTree.update(result, -1);
        }
    }

    return 0;
}