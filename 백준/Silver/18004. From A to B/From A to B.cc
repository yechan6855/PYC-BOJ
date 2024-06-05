#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int,int>
#define mi map<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int32_t main() {
    io;
    int a, b, i = 0;
    cin >> a >> b;

    if (a == b) {
        cout << "0";
    }
    else if (a < b) {
        cout << b - a;
    }
    else {
        while (a > b) {
            if (a % 2 == 1) {
                a++;
            }
            else {
                a /= 2;
            }
            i++;
        }
        cout << i + (b - a);
    }

    return 0;
}