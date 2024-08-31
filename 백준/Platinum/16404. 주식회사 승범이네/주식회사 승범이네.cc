#include <bits/stdc++.h>
#define MAX 100001
using namespace std;\

vector<int> adj[MAX];
int in[MAX], out[MAX], tree[4*MAX], lazy[4*MAX];
int timer = 0;

void dfs(int v) {
    in[v] = ++timer;
    for (int u : adj[v]) {
        dfs(u);
    }
    out[v] = timer;
}

void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, int diff) {
    propagate(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && end <= right) {
        tree[node] += diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, left, right, diff);
    update(node*2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int start, int end, int idx) {
    propagate(node, start, end);
    if (idx < start || idx > end) return 0;
    if (start == end) return tree[node];
    int mid = (start + end) / 2;
    if (idx <= mid) return query(node*2, start, mid, idx);
    else return query(node*2+1, mid+1, end, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        if (p != -1) adj[p].push_back(i);
    }

    dfs(1);

    while (M--) {
        int q, i, w;
        cin >> q;
        if (q == 1) {
            cin >> i >> w;
            update(1, 1, N, in[i], out[i], w);
        } else {
            cin >> i;
            cout << query(1, 1, N, in[i]) << '\n';
        }
    }

    return 0;
}