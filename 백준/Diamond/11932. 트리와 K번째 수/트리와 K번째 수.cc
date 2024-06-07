#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

#define MAXN 100005

struct node {
    int c;
    node *left, *right;
    node(int _c, node *a, node *b) : c(_c), left(a), right(b) {}
    node* upd(int l, int r, int w);
};

node *root[MAXN], *null;

node* node::upd(int l, int r, int w) {
    if (l <= w && w <= r) {
        if (l == r){
            return new node(this->c + 1, null, null);
        }
        int m = (l + r) / 2;
        return new node(this->c + 1, this->left->upd(l, m, w), this->right->upd(m + 1, r, w));
    }
    return this;
}

int N, M, weight[MAXN], eulerTour[MAXN], Xn, depth[MAXN];
mi dx;
vvi tree(MAXN);
int parent[MAXN][17];

void dfs(int node, int par) {
    if (par == -1){
        root[node] = null->upd(1, Xn, weight[node]);
    }
    else{
        root[node] = root[par]->upd(1, Xn, weight[node]);
    }
    for (auto &next : tree[node]) {
        if (next == par){
            continue;
        }
        parent[next][0] = node;
        depth[next] = depth[node] + 1;
        dfs(next, node);
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]){
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = 16; i >= 0; i--){
        if ((diff >> i) & 1){
            u = parent[u][i];
        }
    }
    if (u == v){
        return u;
    }
    for (int i = 16; i >= 0; i--){
        if (parent[u][i] != parent[v][i]){
            u = parent[u][i], v = parent[v][i];
        }
    }
    return parent[u][0];
}

int query(node *a, node *b, node *c, node *d, int l, int r, int k) {
    if (l == r){
        return l;
    }
    int cnt = a->left->c + b->left->c - c->left->c - d->left->c;
    int m = (l + r) / 2;
    if (cnt >= k){
        return query(a->left, b->left, c->left, d->left, l, m, k);
    }
    return query(a->right, b->right, c->right, d->right, m + 1, r, k - cnt);
}

int32_t main() {
    io;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> weight[i];
        eulerTour[i] = weight[i];
    }

    sort(eulerTour + 1, eulerTour + N + 1);
    Xn = unique(eulerTour + 1, eulerTour + N + 1) - (eulerTour + 1);
    for (int i = 1; i <= Xn; i++){
        dx[eulerTour[i]] = i;
    }
    for (int i = 1; i <= N; i++){
        weight[i] = dx[weight[i]];
    }

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    for (int I = 0; I <= N; I++){
        for(int j = 0; j <= 16; j++){
            parent[I][j] = -1;
        }
    }

    null = new node(0, NULL, NULL);
    null->left = null->right = null;
    dfs(1, -1);

    for (int j = 1; j <= 16; j++) {
        for (int I = 1; I <= N; I++) {
            if (parent[I][j - 1] == -1){
                continue;
            }
            parent[I][j] = parent[parent[I][j - 1]][j - 1];
        }
    }

    for (int I = 1; I <= M; I++) {
        int u, v, k;
        cin >> u >> v >> k;
        int x = LCA(u, v);
        int res = query(root[u], root[v], root[x], (parent[x][0] == -1 ? null : root[parent[x][0]]), 1, Xn, k);
        cout << eulerTour[res] << endl;
    }

    return 0;
}