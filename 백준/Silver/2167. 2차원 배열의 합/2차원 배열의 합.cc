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
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int MAX = 301;
int N, M, K;
int arr[MAX][MAX];
ll segtree[MAX * 4][MAX * 4];

void build_y(int node_x, int start_x, int end_x, int node_y, int start_y, int end_y) {
    if (start_y == end_y) {
        if (start_x == end_x) {
            segtree[node_x][node_y] = arr[start_x][start_y];
        } else {
            segtree[node_x][node_y] = segtree[node_x * 2][node_y] + segtree[node_x * 2 + 1][node_y];
        }
    } else {
        int mid_y = (start_y + end_y) / 2;
        build_y(node_x, start_x, end_x, node_y * 2, start_y, mid_y);
        build_y(node_x, start_x, end_x, node_y * 2 + 1, mid_y + 1, end_y);
        segtree[node_x][node_y] = segtree[node_x][node_y * 2] + segtree[node_x][node_y * 2 + 1];
    }
}

void build_x(int node_x, int start_x, int end_x) {
    if (start_x != end_x) {
        int mid_x = (start_x + end_x) / 2;
        build_x(node_x * 2, start_x, mid_x);
        build_x(node_x * 2 + 1, mid_x + 1, end_x);
    }
    build_y(node_x, start_x, end_x, 1, 1, M);
}

ll query_y(int node_x, int node_y, int start_y, int end_y, int l_y, int r_y) {
    if (r_y < start_y || end_y < l_y) return 0;
    if (l_y <= start_y && end_y <= r_y) return segtree[node_x][node_y];
    int mid_y = (start_y + end_y) / 2;
    return query_y(node_x, node_y * 2, start_y, mid_y, l_y, r_y) + query_y(node_x, node_y * 2 + 1, mid_y + 1, end_y, l_y, r_y);
}

ll query_x(int node_x, int start_x, int end_x, int l_x, int r_x, int l_y, int r_y) {
    if (r_x < start_x || end_x < l_x) return 0;
    if (l_x <= start_x && end_x <= r_x) return query_y(node_x, 1, 1, M, l_y, r_y);
    int mid_x = (start_x + end_x) / 2;
    return query_x(node_x * 2, start_x, mid_x, l_x, r_x, l_y, r_y) + query_x(node_x * 2 + 1, mid_x + 1, end_x, l_x, r_x, l_y, r_y);
}

int main() {
    io;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> arr[i][j];
        }
    }

    build_x(1, 1, N);

    cin >> K;
    while (K--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << query_x(1, 1, N, i, x, j, y) << endl;
    }

    return 0;
}