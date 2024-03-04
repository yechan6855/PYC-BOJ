#include <bits/stdc++.h>

using namespace std;

int n, root, del, cnt;
vector<int> tree[51];

void dfs(int node) {
    if (node == del) return;
    if (tree[node].empty()) {
        cnt++;
        return;
    }
    if (tree[node].size() == 1 && tree[node][0] == del) {
        cnt++;
        return;
    }
    for (int i = 0; i < tree[node].size(); i++) {
        dfs(tree[node][i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == -1) root = i;
        else tree[a].push_back(i);
    }
    cin >> del;
    if (del == root) {
        cout << 0;
        return 0;
    }
    dfs(root);
    cout << cnt;
    return 0;
}