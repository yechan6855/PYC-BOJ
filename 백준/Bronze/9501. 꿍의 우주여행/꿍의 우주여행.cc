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

int main() {
    io;
    int T;
    cin >> T;

    while (T--) {
        int N, D;
        cin >> N >> D;
        int cnt = 0;

        for (int i = 0; i < N; ++i) {
            int v, f, c;
            cin >> v >> f >> c;

            double t = (double)D / v;
            double mt = (double)f / c;

            if (t <= mt) {
                ++cnt;
            }
        }

        cout << cnt << endl;
    }
}