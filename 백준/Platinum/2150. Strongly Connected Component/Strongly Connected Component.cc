#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int id = 0;
vector<vector<int>> adj;
vector<int> ids, low;
vector<bool> onStack;
stack<int> st;
vector<vector<int>> sccs;

void dfs(int at) {
    st.push(at);
    onStack[at] = true;
    ids[at] = low[at] = id++;

    for (int to : adj[at]) {
        if (ids[to] == -1) {
            dfs(to);
            low[at] = min(low[at], low[to]);
        } else if (onStack[to]) {
            low[at] = min(low[at], ids[to]);
        }
    }

    if (ids[at] == low[at]) {
        vector<int> scc;
        while (true) {
            int node = st.top();
            st.pop();
            onStack[node] = false;
            scc.push_back(node);
            low[node] = ids[at];
            if (node == at) break;
        }
        sccs.push_back(scc);
    }
}

void findSCCs(int n) {
    ids.assign(n, -1);
    low.assign(n, 0);
    onStack.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (ids[i] == -1) {
            dfs(i);
        }
    }
}

int main() {
    io;
    int V, E;
    cin >> V >> E;
    adj.resize(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }

    findSCCs(V);

    for (auto& scc : sccs) {
        sort(scc.begin(), scc.end());
    }
    sort(sccs.begin(), sccs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    cout << sccs.size() << endl;
    for (auto& scc : sccs) {
        for (int node : scc) {
            cout << node + 1 << " ";
        }
        cout << -1 << endl;
    }

    return 0;
}