#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int MAX_N = 500000 + 1;

class FenwickTree {
private:
    vector<int> tree;
    int size;
public:
    FenwickTree(int n) : size(n) {
        tree.resize(n+1, 0);
    }

    void update(int idx, int val) {
        while (idx <= size) {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    map<int, int> indexMap;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        indexMap[b[i]] = i;
    }

    FenwickTree bit(n);
    long long inversions = 0;

    for (int i = 1; i <= n; i++) {
        int pos = indexMap[a[i]];
        inversions += i - 1 - bit.query(pos);
        bit.update(pos, 1);
    }

    cout << inversions << endl;

    return 0;
}