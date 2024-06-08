#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define di deque<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

vi LPS(const string &pat) {
    int M = pat.length();
    vi lps(M);
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int findMaxN(const string &s) {
    int len = s.length();
    vi lps = LPS(s);

    int suffix = lps[len - 1];
    int prefix = len - suffix;

    if (len % prefix == 0) {
        return len / prefix;
    } else {
        return 1;
    }
}

int main() {
    io;
    string s;
    while (true) {
        cin >> s;
        if (s == ".") break;
        cout << findMaxN(s) << endl;
    }
    return 0;
}