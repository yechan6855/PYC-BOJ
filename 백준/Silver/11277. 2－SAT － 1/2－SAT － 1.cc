#include <bits/stdc++.h>
#define MAX 20001
using namespace std;

int N, M;
vector<int> graph[MAX];
vector<int> rev_graph[MAX];
bool visited[MAX];
stack<int> st;
int scc[MAX];
int cnt = 0;

void dfs(int node) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) dfs(next);
    }
    st.push(node);
}

void rev_dfs(int node) {
    visited[node] = true;
    scc[node] = cnt;
    for (int next : rev_graph[node]) {
        if (!visited[next]) rev_dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a = (a > 0) ? 2 * a : -2 * a + 1;
        b = (b > 0) ? 2 * b : -2 * b + 1;
        graph[a ^ 1].push_back(b);
        graph[b ^ 1].push_back(a);
        rev_graph[b].push_back(a ^ 1);
        rev_graph[a].push_back(b ^ 1);
    }

    for (int i = 2; i <= 2 * N + 1; i++) {
        if (!visited[i]) dfs(i);
    }

    fill(visited, visited + MAX, false);

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            cnt++;
            rev_dfs(node);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (scc[2 * i] == scc[2 * i + 1]) {
            cout << 0 << '\n';
            return 0;
        }
    }

    cout << 1 << '\n';
    return 0;
}