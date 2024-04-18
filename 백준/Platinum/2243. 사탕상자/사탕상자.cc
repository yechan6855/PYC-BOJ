#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;

vector<long long> tree(MAX * 4);

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) return;
    if (start == end) {
        tree[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int k) {
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (k <= tree[node * 2]) return query(node * 2, start, mid, k);
    else return query(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a;
        
        if (a == 1) {
            cin >> b;
            
            int idx = query(1, 1, MAX, b);
            cout << idx << '\n';
            update(1, 1, MAX, idx, -1);
        } else {
            cin >> b >> c;
            
            update(1, 1, MAX, b, c);
        }
    }
    return 0;
}