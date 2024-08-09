#include <bits/stdc++.h>
using namespace std;

int N;
int S[20][20];
bool sel[20];
int ans = 1e9;

void dfs(int idx, int cnt) {
    if (cnt == N / 2) {
        int stm = 0, lnk = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (sel[i] && sel[j]) stm += S[i][j];
                if (!sel[i] && !sel[j]) lnk += S[i][j];
            }
        }
        ans = min(ans, abs(stm - lnk));
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!sel[i]) {
            sel[i] = true;
            dfs(i + 1, cnt + 1);
            sel[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    dfs(0, 0);

    cout << ans << '\n';

    return 0;
}