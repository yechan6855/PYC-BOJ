#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAXN = 100000;
const int INF = MAXN + 1;
vi tree[MAXN + 1];
int parent[MAXN + 1], subtree_size[MAXN + 1], heavy[MAXN + 1];
int head[MAXN + 1], pos[MAXN + 1], rpos[MAXN + 1];
int cur_pos;
int segtree[4 * MAXN];
bool color[MAXN + 1];

void dfs(int v) {
    subtree_size[v] = 1;
    for (int c : tree[v]) {
        if (c == parent[v]) continue;
        parent[c] = v;
        dfs(c);
        subtree_size[v] += subtree_size[c];
        if (heavy[v] == -1 || subtree_size[c] > subtree_size[heavy[v]]) {
            heavy[v] = c;
        }
    }
}

void hld(int v, int h) {
    head[v] = h;
    pos[v] = cur_pos++;
    rpos[pos[v]] = v;

    if (heavy[v] != -1) {
        hld(heavy[v], h);
    }
    for (int c : tree[v]) {
        if (c != parent[v] && c != heavy[v]) {
            hld(c, c);
        }
    }
}

void update(int idx, int s, int e, int pos, int val) {
    if (s == e) {
        segtree[idx] = val;
    } else {
        int mid = (s + e) / 2;
        if (pos <= mid)
            update(2 * idx, s, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, e, pos, val);
        segtree[idx] = min(segtree[2 * idx], segtree[2 * idx + 1]);
    }
}

int query(int idx, int s, int e, int l, int r) {
    if (r < s || l > e) return INF;
    if (l <= s && e <= r) return segtree[idx];
    int mid = (s + e) / 2;
    return min(query(2 * idx, s, mid, l, r), query(2 * idx + 1, mid + 1, e, l, r));
}

int query_up(int u) {
    int res = INF;
    while (head[u] != head[1]) {
        res = min(res, query(1, 0, cur_pos - 1, pos[head[u]], pos[u]));
        u = parent[head[u]];
    }
    res = min(res, query(1, 0, cur_pos - 1, pos[1], pos[u]));
    return res;
}

int main() {
    io;
    int N, M;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    memset(heavy, -1, sizeof(heavy));
    memset(subtree_size, 0, sizeof(subtree_size));
    parent[1] = -1;
    cur_pos = 0;
    dfs(1);
    hld(1, 1);

    fill(segtree, segtree + 4 * MAXN, INF);

    cin >> M;
    while (M--) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            color[v] = !color[v];
            update(1, 0, cur_pos - 1, pos[v], color[v] ? pos[v] : INF);
        } else {
            int res = query_up(v);
            cout << (res == INF ? -1 : rpos[res]) << endl;
        }
    }

    return 0;
}