#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> solve(string pattern) {
    int m = pattern.length();
    vector<int> pi(m);
    pi[0] = 0;

    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];

        if (pattern[i] == pattern[j])
            j++;

        pi[i] = j;
    }

    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L;
    string ad;

    cin >> L >> ad;

    vector<int> pi = solve(ad);
    cout << L - pi[L - 1] << endl;

    return 0;
}