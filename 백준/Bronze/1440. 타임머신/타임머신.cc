#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

bool solve(ll h, ll m, ll s) {
    return (1 <= h && h <= 12) && (0 <= m && m <= 59) && (0 <= s && s <= 59);
}

int main() {
    io;
    string t;
    cin >> t;

    int a[3];

    a[0] = stoi(t.substr(0, 2));
    a[1] = stoi(t.substr(3, 2));
    a[2] = stoi(t.substr(6, 2));

    int cnt = 0;

    if(solve(a[0], a[1], a[2])) cnt++;
    if(solve(a[0], a[2], a[1])) cnt++;
    if(solve(a[1], a[0], a[2])) cnt++;
    if(solve(a[1], a[2], a[0])) cnt++;
    if(solve(a[2], a[0], a[1])) cnt++;
    if(solve(a[2], a[1], a[0])) cnt++;

    cout << cnt << endl;
    return 0;
}