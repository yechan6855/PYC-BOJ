#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
vector<int> tree[MAX];
int dp[MAX];

void dfs(int node, int parent) {
    dp[node] = 1;
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            dp[node] += dp[child];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, Q;
    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    dfs(R, -1);

    for (int i = 0; i < Q; i++) {
        int U;
        cin >> U;
        cout << dp[U] << '\n';
    }

    return 0;
}