#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int MAX_L = 100000;
const int MAX_N = 500;
const int MAX_P = 10000;

vi failed(const string& pattern) {
    int m = pattern.size();
    vi fail(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = fail[j - 1];
        if (pattern[i] == pattern[j])
            fail[i] = ++j;
    }
    return fail;
}

int main() {
    io;
    string longStr;
    int N;
    cin >> longStr;
    cin >> N;

    vector<string> shortStrs(N);
    for (int i = 0; i < N; i++)
        cin >> shortStrs[i];

    int L = longStr.size();
    vi dp(L + 1, 0);
    bitset<MAX_L> matched[MAX_N];

    for (int k = 0; k < N; k++) {
        vi fail = failed(shortStrs[k]);
        int m = shortStrs[k].size();
        int j = 0;

        for (int i = 0; i < L; i++) {
            while (j > 0 && longStr[i] != shortStrs[k][j])
                j = fail[j - 1];
            if (longStr[i] == shortStrs[k][j]) {
                if (j == m - 1) {
                    matched[k].set(i - m + 1);
                    j = fail[j];
                } else {
                    j++;
                }
            }
        }
    }

    for (int i = L - 1; i >= 0; i--) {
        if (i < L - 1)
            dp[i] = dp[i + 1];
        for (int k = 0; k < N; k++) {
            int m = shortStrs[k].size();
            if (i + m <= L && matched[k][i]) {
                dp[i] = max(dp[i], m + dp[i + m]);
            }
        }
    }

    cout << dp[0] << endl;

    return 0;
}