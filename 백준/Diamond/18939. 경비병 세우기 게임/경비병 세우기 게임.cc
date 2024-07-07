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
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

string solve(int n, int m, int k) {
    if (max(n, m) < k * 2) {
        return "Yuto";
    }

    return (n * m % 2 == 1) ? "Yuto" : "Platina";
}

int main() {
    io;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << solve(n, m, k) << endl;
    }

    return 0;
}