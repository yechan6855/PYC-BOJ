#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> s(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> s[i];
    }

    vector<int> parent(N + 1, -1);

    vector<vector<int> > chd(N + 1);

    for (int op = 0; op < N - 1; ++op) {
        int i, j;
        cin >> i >> j;
        parent[j] = i;
        chd[i].push_back(j);
    }

    int root = -1;
    for (int i = 1; i <= N; ++i) {
        if (parent[i] == -1) {
            root = i;
            break;
        }
    }

    string ans;
    ans.reserve(500000);

    stack<int> stk;
    stk.push(root);

    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();

        ans += s[node];

        for (auto it = chd[node].rbegin(); it != chd[node].rend(); ++it) {
            stk.push(*it);
        }
    }

    cout << ans;

    return 0;
}