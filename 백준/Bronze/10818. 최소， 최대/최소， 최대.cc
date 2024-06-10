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
#define MAX INT_MAX
#define MIN INT_MIN
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct SegmentTree {
    int n;
    vi min_tree;
    vi max_tree;

    SegmentTree(const vi& data) {
        n = data.size();
        min_tree.resize(4 * n);
        max_tree.resize(4 * n);
        build(data, 0, n - 1, 1);
    }

    void build(const vi& data, int start, int end, int node) {
        if (start == end) {
            min_tree[node] = data[start];
            max_tree[node] = data[start];
            return;
        }
        int mid = (start + end) / 2;
        build(data, start, mid, node * 2);
        build(data, mid + 1, end, node * 2 + 1);
        min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
        max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
    }

    int query_min(int left, int right, int start, int end, int node) {
        if (right < start || end < left) {
            return MAX;
        }
        if (left <= start && end <= right) {
            return min_tree[node];
        }
        int mid = (start + end) / 2;
        return min(query_min(left, right, start, mid, node * 2),
                   query_min(left, right, mid + 1, end, node * 2 + 1));
    }

    int query_max(int left, int right, int start, int end, int node) {
        if (right < start || end < left) {
            return MIN;
        }
        if (left <= start && end <= right) {
            return max_tree[node];
        }
        int mid = (start + end) / 2;
        return max(query_max(left, right, start, mid, node * 2),
                   query_max(left, right, mid + 1, end, node * 2 + 1));
    }

    int query_min(int left, int right) {
        return query_min(left, right, 0, n - 1, 1);
    }

    int query_max(int left, int right) {
        return query_max(left, right, 0, n - 1, 1);
    }
};

int main() {
    io;
    int N;
    cin >> N;
    vi data(N);

    for (int i = 0; i < N; ++i) {
        cin >> data[i];
    }

    SegmentTree segTree(data);

    int min_ans = segTree.query_min(0, N - 1);
    int max_ans = segTree.query_max(0, N - 1);

    cout << min_ans << " " << max_ans << endl;

    return 0;
}