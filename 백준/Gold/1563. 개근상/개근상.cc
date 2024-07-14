#include <bits/stdc++.h>
#define endl "\n"
#define MOD 1000000
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int dp[1001][2][3] = {0};

int main() {
    io;
    int N;
    cin >> N;

    dp[0][0][0] = 1;

    for (int day = 1; day <= N; ++day) {
        for (int late = 0; late < 2; ++late) {
            for (int absent = 0; absent < 3; ++absent) {
                dp[day][late][0] = (dp[day][late][0] + dp[day-1][late][absent]) % MOD;

                if (late < 1) {
                    dp[day][late+1][0] = (dp[day][late+1][0] + dp[day-1][late][absent]) % MOD;
                }

                if (absent < 2) {
                    dp[day][late][absent+1] = (dp[day][late][absent+1] + dp[day-1][late][absent]) % MOD;
                }
            }
        }
    }

    int result = 0;
    for (int late = 0; late < 2; ++late) {
        for (int absent = 0; absent < 3; ++absent) {
            result = (result + dp[N][late][absent]) % MOD;
        }
    }

    cout << result << endl;
    return 0;
}