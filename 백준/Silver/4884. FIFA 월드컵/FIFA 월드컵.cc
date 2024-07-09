#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int32_t main(){
    io;
    while (1) {
        int G, T, A, D;
        cin >> G >> T >> A >> D;
        if (G == -1 && T == -1 && A == -1 && D == -1) break;

        int g = G * (T * (T - 1) / 2);
        int t = G * A + D;

        int p = pow(2, ceil(log2(t)));
        int a = p - t;
        int m = p - 1;

        int x = g + m;

        cout << G << "*" << A << "/" << T << "+" << D << "=" << x << "+" << a << endl;
    }
    return 0;
}