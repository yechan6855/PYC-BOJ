#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define as assign
#define pi pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct Node {
    int val;
    int index;
};

void build(vector<Node>& tree, vi& scores, int start, int end, int node) {
    if (start == end) {
        tree[node] = {scores[start], start + 1};
    } else {
        int mid = (start + end) / 2;
        build(tree, scores, start, mid, 2 * node + 1);
        build(tree, scores, mid + 1, end, 2 * node + 2);
        if (tree[2 * node + 1].val > tree[2 * node + 2].val) {
            tree[node] = tree[2 * node + 1];
        } else {
            tree[node] = tree[2 * node + 2];
        }
    }
}

Node query(vector<Node>& tree, int start, int end, int l, int r, int node) {
    if (r < start || l > end) {
        return {-1, -1};
    }
    if (l <= start && r >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    Node left = query(tree, start, mid, l, r, 2 * node + 1);
    Node right = query(tree, mid + 1, end, l, r, 2 * node + 2);
    if (left.val > right.val) {
        return left;
    } else {
        return right;
    }
}

int32_t main() {
    io;
    vvi scores(5, vi(4));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> scores[i][j];
        }
    }

    vi total(5);
    for (int i = 0; i < 5; i++) {
        total[i] = scores[i][0] + scores[i][1] + scores[i][2] + scores[i][3];
    }

    int n = total.size();
    vector<Node> segment_tree(4 * n);
    build(segment_tree, total, 0, n - 1, 0);

    Node result = query(segment_tree, 0, n - 1, 0, n - 1, 0);
    cout << result.index << " " << result.val << endl;

    return 0;
}