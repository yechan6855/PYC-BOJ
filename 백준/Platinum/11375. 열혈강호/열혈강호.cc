#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX = 1001;

int N, M;
vector<int> work[MAX];
int assigned[MAX];
bool visited[MAX];

bool dfs(int employee) {
    for (int task : work[employee]) {
        if (visited[task]) continue;
        visited[task] = true;

        if (assigned[task] == 0 || dfs(assigned[task])) {
            assigned[task] = employee;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int task;
            cin >> task;
            work[i].push_back(task);
        }
    }

    int maxWork = 0;
    memset(assigned, 0, sizeof(assigned));

    for (int i = 1; i <= N; ++i) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) {
            maxWork++;
        }
    }

    cout << maxWork << endl;
    return 0;
}