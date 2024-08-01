#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

vector<int> computePI(const string& pattern) {
    int m = pattern.length();
    vector<int> pi(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j-1];
        }
        if (pattern[i] == pattern[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

int solve(const string& s) {
    int n = s.length();
    int result = 0;

    for (int i = 0; i < n; i++) {
        vector<int> pi = computePI(s.substr(i));
        result = max(result, *max_element(pi.begin(), pi.end()));
    }

    return result;
}

int main() {
    io;
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}