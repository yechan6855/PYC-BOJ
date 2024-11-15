#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> Lps(const string &pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int length = 0;

    for(int i = 1; i < n; i++) {
        while(length > 0 && pattern[i] != pattern[length]) {
            length = lps[length - 1];
        }
        if(pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
        }
    }
    return lps;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    ll k;
    cin >> s >> k;

    vector<int> lps = Lps(s);
    int n = s.length();
    int last = lps[n-1];

    ll ans = (ll)n + (k-1) * ((ll)n - (ll)last);

    cout << ans;
}