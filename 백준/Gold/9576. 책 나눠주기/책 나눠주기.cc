#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1001; // MAX의 실제 값은 문제에 따라 조정해야 합니다.

vector<int> arr[MAX];
bool c[MAX];
int d[MAX];

bool dfs(int node) {
    if (c[node]) return false;
    c[node] = true;

    for (int i = 0; i < arr[node].size(); i++) {
        int next = arr[node][i];
        if (d[next] == 0 || dfs(d[next])) {
            d[next] = node;
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            for (int j = a; j <= b; j++) {
                arr[i].push_back(j);
            }
        }

        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            fill(c, c + MAX, false);
            if (dfs(i)) cnt++;
        }
        cout << cnt << '\n';

        for (int i = 1; i <= m; i++) {
            arr[i].clear();
        }
        fill(d, d + MAX, 0);
    }
    return 0;
}