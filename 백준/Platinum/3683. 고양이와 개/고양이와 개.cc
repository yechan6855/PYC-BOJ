#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define di deque<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int MAX_V = 505;

vi adj[MAX_V];
int match[MAX_V], visited[MAX_V];
int c, d, v;

bool bipartite(int u) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        if (match[v] == -1 || bipartite(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        cin >> c >> d >> v;

        for (int i = 0; i < MAX_V; i++) {
            adj[i].clear();
        }

        vector<pi> cat, dog;
        for (int i = 0; i < v; ++i) {
            string a, b;
            cin >> a >> b;
            int aIndex = stoi(a.substr(1));
            int bIndex = stoi(b.substr(1));
            if (a[0] == 'C') {
                cat.emplace_back(aIndex, bIndex);
            } else {
                dog.emplace_back(aIndex, bIndex);
            }
        }

        for (int i = 0; i < cat.size(); ++i) {
            for (int j = 0; j < dog.size(); ++j) {
                if (cat[i].fi == dog[j].se || cat[i].se == dog[j].fi) {
                    adj[i].pb(j);
                }
            }
        }

        memset(match, -1, sizeof(match));
        int cnt = 0;
        for (int i = 0; i < cat.size(); ++i) {
            memset(visited, 0, sizeof(visited));
            if (bipartite(i)) {
                cnt++;
            }
        }

        cout << v - cnt << endl;
    }

    return 0;
}