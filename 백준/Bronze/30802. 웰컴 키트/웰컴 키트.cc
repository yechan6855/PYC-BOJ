#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int,int>
#define mi map<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

class SegmentTree {
public:
    SegmentTree(vi& data) {
        n = data.size();
        tree.resize(2 * n);
        build(data);
    }

    void update(int pos, int value) {
        pos += n;
        tree[pos] = value;
        while (pos > 1) {
            pos >>= 1;
            tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
        }
    }

    int query(int left, int right) {
        int res = 0;
        left += n;
        right += n;
        while (left < right) {
            if (left & 1) res += tree[left++];
            if (right & 1) res += tree[--right];
            left >>= 1;
            right >>= 1;
        }
        return res;
    }

private:
    vi tree;
    int n;

    void build(vi& data) {
        for (int i = 0; i < n; ++i)
            tree[i + n] = data[i];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
};

int32_t main() {
    io;
    int N;
    cin >> N;

    vi s(6);
    for (int i = 0; i < 6; ++i) {
        cin >> s[i];
    }

    int T, P;
    cin >> T >> P;

    SegmentTree segTree(s);

    int t = 0;
    for (int i = 0; i < 6; ++i) {
        int n = segTree.query(i, i + 1);
        int b = (n + T - 1) / T;
        t += b;
    }

    int m = N / P;
    int r = N % P;

    cout << t << endl;
    cout << m << " " << r << endl;

    return 0;
}