#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<int> dist(n + 1, -1);
    dist[x] = 0;

    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            ans.push_back(i);
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        sort(ans.begin(), ans.end());
        for (int result : ans) {
            cout << result << endl;
        }
    }

    return 0;
}