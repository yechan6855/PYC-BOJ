#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int INF = 987654321;
int N, P;
int cost[16][16];
int dp[1 << 16];
string initial_state;

int solve(int state) {
    if (__builtin_popcount(state) >= P) {
        return 0;
    }

    int &ret = dp[state];
    if (ret != -1) {
        return ret;
    }

    ret = INF;
    for (int i = 0; i < N; i++) {
        if (state & (1 << i)) {
            for (int j = 0; j < N; j++) {
                if (!(state & (1 << j))) {
                    ret = min(ret, cost[i][j] + solve(state | (1 << j)));
                }
            }
        }
    }

    return ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    cin >> initial_state;
    cin >> P;

    int initial_state_mask = 0;
    for (int i = 0; i < N; i++) {
        if (initial_state[i] == 'Y') {
            initial_state_mask |= (1 << i);
        }
    }

    memset(dp, -1, sizeof(dp));
    int result = solve(initial_state_mask);

    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}