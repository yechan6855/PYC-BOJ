#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
vector<int> g[MAX];
bool v[MAX];
int d[MAX], l[MAX];
bool a[MAX];
int t;

void dfs(int node, int parent) {
    v[node] = true;
    d[node] = l[node] = ++t;
    int c = 0;

    for (int next : g[node]) {
        if (next == parent) continue;

        if (v[next]) {
            l[node] = min(l[node], d[next]);
        } else {
            dfs(next, node);
            l[node] = min(l[node], l[next]);

            if (l[next] >= d[node] && parent != -1)
                a[node] = true;

            c++;
        }
    }

    if (parent == -1 && c > 1)
        a[node] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fill(v, v + MAX, false);
    fill(a, a + MAX, false);
    t = 0;

    for (int i = 1; i <= n; i++) {
        if (!v[i])
            dfs(i, -1);
    }

    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (a[i])
            result.push_back(i);
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (int point : result) {
        cout << point << ' ';
    }
    cout << '\n';

    return 0;
}