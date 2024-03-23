#include <bits/stdc++.h>

using namespace std;

const int MAX_WEIGHT = 40000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<bool> dp(MAX_WEIGHT + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; ++i) {
        int weight;
        cin >> weight;
        vector<bool> temp(dp);

        for (int j = 0; j <= MAX_WEIGHT; ++j) {
            if (dp[j]) {
                if (j + weight <= MAX_WEIGHT) temp[j + weight] = true;
                temp[abs(j - weight)] = true;
            }
        }
        dp = temp;
    }

    int k;
    cin >> k;

    while (k--) {
        int item;
        cin >> item;
        if (item <= MAX_WEIGHT && dp[item]) {
            cout << "Y ";
        } else {
            cout << "N ";
        }
    }

    return 0;
}