#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAXN = 100005;
const int LOGN = 17;

vector<pii> tree[MAXN];
int dep[MAXN], par[MAXN][LOGN], maxEdge[MAXN][LOGN];
int head[MAXN], pos[MAXN], chainIdx[MAXN], subSize[MAXN];
int baseArr[MAXN], segTree[4 * MAXN];
int N, M, chainCnt, baseIdx;

struct Edge {
    int u, v, w;
} edges[MAXN];

void dfs(int u, int p, int d) {
    par[u][0] = p;
    dep[u] = d;
    subSize[u] = 1;
    for (auto &[v, w] : tree[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
        subSize[u] += subSize[v];
    }
}

void hld(int u, int p, int cost) {
    if (head[chainCnt] == -1) {
        head[chainCnt] = u;
    }
    chainIdx[u] = chainCnt;
    pos[u] = baseIdx;
    baseArr[baseIdx++] = cost;

    int sc = -1, nw = 0;
    for (auto &[v, w] : tree[u]) {
        if (v == p) continue;
        if (sc == -1 || subSize[v] > subSize[sc]) {
            sc = v;
            nw = w;
        }
    }

    if (sc != -1) {
        hld(sc, u, nw);
    }

    for (auto &[v, w] : tree[u]) {
        if (v == p || v == sc) continue;
        chainCnt++;
        hld(v, u, w);
    }
}

void buildSegTree(int node, int start, int end) {
    if (start == end) {
        segTree[node] = baseArr[start];
    } else {
        int mid = (start + end) / 2;
        buildSegTree(2 * node, start, mid);
        buildSegTree(2 * node + 1, mid + 1, end);
        segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
    }
}

void updateSegTree(int node, int start, int end, int idx, int value) {
    if (start == end) {
        baseArr[idx] = value;
        segTree[node] = value;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            updateSegTree(2 * node, start, mid, idx, value);
        } else {
            updateSegTree(2 * node + 1, mid + 1, end, idx, value);
        }
        segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
    }
}

int querySegTree(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
        return 0;
    }
    if (L <= start && end <= R) {
        return segTree[node];
    }
    int mid = (start + end) / 2;
    return max(querySegTree(2 * node, start, mid, L, R), querySegTree(2 * node + 1, mid + 1, end, L, R));
}

void preprocess() {
    memset(head, -1, sizeof(head));
    chainCnt = 0;
    baseIdx = 0;
    dfs(1, -1, 0);
    hld(1, -1, 0);
    buildSegTree(1, 0, baseIdx - 1);

    for (int j = 1; j < LOGN; ++j) {
        for (int i = 1; i <= N; ++i) {
            if (par[i][j - 1] != -1) {
                par[i][j] = par[par[i][j - 1]][j - 1];
                maxEdge[i][j] = max(maxEdge[i][j - 1], maxEdge[par[i][j - 1]][j - 1]);
            }
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int i = 0; i < LOGN; ++i) {
        if ((diff >> i) & 1) {
            u = par[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int queryHLD(int u, int v) {
    int res = 0;
    while (chainIdx[u] != chainIdx[v]) {
        if (dep[head[chainIdx[u]]] < dep[head[chainIdx[v]]]) swap(u, v);
        res = max(res, querySegTree(1, 0, baseIdx - 1, pos[head[chainIdx[u]]], pos[u]));
        u = par[head[chainIdx[u]]][0];
    }
    if (u == v) return res;
    if (dep[u] > dep[v]) swap(u, v);
    return max(res, querySegTree(1, 0, baseIdx - 1, pos[u] + 1, pos[v]));
}

void changeEdge(int i, int cost) {
    int u = edges[i].u;
    int v = edges[i].v;
    if (dep[u] < dep[v]) swap(u, v);
    updateSegTree(1, 0, baseIdx - 1, pos[u], cost);
}

int main() {
    io;
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].pb({v, w});
        tree[v].pb({u, w});
        edges[i] = {u, v, w};
    }
    preprocess();

    cin >> M;
    while (M--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            changeEdge(a, b);
        } else {
            cout << queryHLD(a, b) << endl;
        }
    }

    return 0;
}