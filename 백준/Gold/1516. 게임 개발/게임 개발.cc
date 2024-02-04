#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> indegree(n + 1, 0);
    vector<int> time(n + 1, 0);
    vector<int> result(n + 1, 0);
    vector<vector<int>> graph(n + 1);

    for (int i = 1; i <= n; ++i) {
        int buildTime;
        cin >> buildTime;
        time[i] = buildTime;

        while (true) {
            int prerequisite;
            cin >> prerequisite;
            if (prerequisite == -1) break;
            graph[prerequisite].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            result[i] = time[i];
        }
    }
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            indegree[next]--;
            result[next] = max(result[next], result[current] + time[next]);

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << result[i] << '\n';
    }
    return 0;
}