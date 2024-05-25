#include <bits/stdc++.h>
using namespace std;

const int MAX = 201;

int N, M;
vector<int> adj[MAX];
int bMatched[MAX];
bool visited[MAX];

bool dfs(int cow) {
    for (int barn : adj[cow]) {
        if (visited[barn]) continue;
        visited[barn] = true;
        if (bMatched[barn] == -1 || dfs(bMatched[barn])) {
            bMatched[barn] = cow;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        int S;
        cin >> S;
        for (int j = 0; j < S; ++j) {
            int barn;
            cin >> barn;
            adj[i].push_back(barn);
        }
    }

    memset(bMatched, -1, sizeof(bMatched));

    int matchCount = 0;
    for (int cow = 1; cow <= N; ++cow) {
        memset(visited, false, sizeof(visited));
        if (dfs(cow)) {
            ++matchCount;
        }
    }

    cout << matchCount << endl;

    return 0;
}