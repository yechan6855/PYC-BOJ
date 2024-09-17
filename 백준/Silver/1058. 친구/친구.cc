#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<bool>> friends(N, vector<bool>(N, false));
    vector<vector<int>> dist(N, vector<int>(N, 987654321));

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == 'Y') {
                friends[i][j] = true;
                dist[i][j] = 1;
            }
            if (i == j) dist[i][j] = 0;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (i != j && dist[i][j] <= 2) count++;
        }
        ans = max(ans, count);
    }

    cout << ans << endl;

    return 0;
}