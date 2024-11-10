#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

struct SegmentTreeNode {
    long long value;
    int left, right;
    int lazy;
};

class SegmentTree {
private:
    vector<SegmentTreeNode> tree;

    SegmentTreeNode makeNode(long long value, int left, int right) {
        return { value, left, right, 0 };
    }

    long long calculate(int node, int left, int right) {
        if (tree[node].lazy != 0) {
            tree[node].value = tree[node].lazy;
            if (left != right) {
                tree[node * 2].lazy = tree[node].lazy;
                tree[node * 2 + 1].lazy = tree[node].lazy;
            }
            tree[node].lazy = 0;
        }
        if (left > right || left > tree[node].right || right < tree[node].left)
            return 1;
        if (left <= tree[node].left && tree[node].right <= right)
            return tree[node].value;
        int mid = (tree[node].left + tree[node].right) / 2;
        long long leftValue = calculate(node * 2, left, min(right, mid));
        long long rightValue = calculate(node * 2 + 1, max(left, mid + 1), right);
        return (leftValue * rightValue) % MOD;
    }

    void update(int node, int index, int value) {
        if (tree[node].lazy != 0) {
            tree[node].value = tree[node].lazy;
            if (tree[node].left != tree[node].right) {
                tree[node * 2].lazy = tree[node].lazy;
                tree[node * 2 + 1].lazy = tree[node].lazy;
            }
            tree[node].lazy = 0;
        }
        if (index < tree[node].left || index > tree[node].right)
            return;
        if (tree[node].left == tree[node].right) {
            tree[node].value = value;
            return;
        }
        int mid = (tree[node].left + tree[node].right) / 2;
        update(node * 2, index, value);
        update(node * 2 + 1, index, value);
        tree[node].value = (tree[node * 2].value * tree[node * 2 + 1].value) % MOD;
    }

public:
    void init(vector<int>& nums) {
        int n = nums.size();
        tree.resize(n * 4);
        init(1, 0, n - 1, nums);
    }

    void init(int node, int left, int right, vector<int>& nums) {
        if (left == right) {
            tree[node] = makeNode(nums[left], left, right);
            return;
        }
        int mid = (left + right) / 2;
        init(node * 2, left, mid, nums);
        init(node * 2 + 1, mid + 1, right, nums);
        tree[node] = makeNode((tree[node * 2].value * tree[node * 2 + 1].value) % MOD, left, right);
    }

    long long calculate(int left, int right) {
        return calculate(1, left, right);
    }

    void update(int index, int value) {
        update(1, index, value);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    SegmentTree segmentTree;
    segmentTree.init(nums);

    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            segmentTree.update(b - 1, c);
        } else if (a == 2) {
            long long result = segmentTree.calculate(b - 1, c - 1);
            cout << result << '\n';
        }
    }

    return 0;
}