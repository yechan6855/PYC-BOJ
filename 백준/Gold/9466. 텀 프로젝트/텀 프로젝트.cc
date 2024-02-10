#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
int students[MAX];
bool visited[MAX];
bool finished[MAX];
int result;

void dfs(int node) {
    visited[node] = true;
    int next = students[node];

    if (!visited[next]) {
        dfs(next);
    } else {
        if (!finished[next]) {
            for (int i = next; i != node; i = students[i]) {
                result++;
            }
            result++;  // 자기 자신도 포함
        }
    }

    finished[node] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> students[i];
            visited[i] = false;
            finished[i] = false;
        }

        result = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << n - result << '\n';
    }
    return 0;
}