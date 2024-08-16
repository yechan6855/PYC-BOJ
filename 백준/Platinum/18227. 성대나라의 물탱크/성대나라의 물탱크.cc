#include <bits/stdc++.h>
#define ll long long
#define MAX 200001
using namespace std;

vector<int> graph[MAX];
int start[MAX], end_time[MAX], depth[MAX];
ll tree[MAX * 4];
int timer = 0;

void dfs(int node, int parent, int d) {
    start[node] = ++timer;
    depth[node] = d;
    for (int child : graph[node]) {
        if (child != parent) {
            dfs(child, node, d + 1);
        }
    }
    end_time[node] = timer;
}

void update(int node, int start, int end, int idx, ll diff) {
    if (idx < start || idx > end) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(c, 0, 1);

    int q;
    cin >> q;

    while (q--) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            update(1, 1, n, start[x], 1);
        } else {
            ll result = query(1, 1, n, start[x], end_time[x]) * depth[x];
            cout << result << '\n';
        }
    }

    return 0;
}