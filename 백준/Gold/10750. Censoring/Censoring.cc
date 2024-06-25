#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

string solve(string S, string T) {
    string result;
    int tLen = T.length();

    for (char ch : S) {
        result.push_back(ch);

        if (result.size() >= tLen && result.substr(result.size() - tLen, tLen) == T) {
            result.resize(result.size() - tLen);
        }
    }

    return result;
}

int32_t main() {
    string S, T;
    cin >> S >> T;

    cout << solve(S, T) << endl;
    return 0;
}