#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int in[MAX], out[MAX], tree[MAX * 4];
int timer = 0;

vector<int> adj[MAX];

void dfs(int cur) {
    in[cur] = ++timer;
    for (int next : adj[cur]) {
        dfs(next);
    }
    out[cur] = timer;
}

void update(int node, int start, int end, int left, int right, int val) {
    if (right < start || end < left) return;
    if (left <= start && end <= right) {
        tree[node] += val;
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val);
    update(node * 2 + 1, mid + 1, end, left, right, val);
}

int query(int node, int start, int end, int idx) {
    if (idx < start || end < idx) return 0;
    if (start == end) return tree[node];

    int mid = (start + end) / 2;

    return tree[node] + query(node * 2, start, mid, idx) + query(node * 2 + 1, mid + 1, end, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p != -1) {
            adj[p].push_back(i);
        }
    }

    dfs(1);

    while (m--) {
        int t;
        cin >> t;

        if (t == 1) {
            int i, w;
            cin >> i >> w;
            update(1, 1, n, in[i], out[i], w);
        } else {
            int i;
            cin >> i;
            cout << query(1, 1, n, in[i]) << '\n';
        }
    }

    return 0;
}