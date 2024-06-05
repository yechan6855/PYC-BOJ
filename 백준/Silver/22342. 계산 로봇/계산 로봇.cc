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
    int M, N;
    cin >> M >> N;

    vvi D(M, vi(N));
    for (int i = 0; i < M; ++i) {
        string l;
        cin >> l;
        for (int j = 0; j < N; ++j) {
            D[i][j] = l[j] - '0';
        }
    }

    vvi s(M, vi(N, 0));
    vvi out(M, vi(N, 0));

    for (int i = 0; i < M; ++i) {
        s[i][0] = 0;
        out[i][0] = D[i][0];
    }

    for (int j = 1; j < N; ++j) {
        vi val(M, 0);
        for (int b = 0; b < j; ++b) {
            for (int a = 0; a < M; ++a) {
                val[a] = max(val[a], out[a][b]);
            }
        }
        for (int i = 0; i < M; ++i) {
            int in = 0;
            for (int a = 0; a < M; ++a) {
                if (abs(i - a) <= j) {
                    in = max(in, val[a]);
                }
            }
            s[i][j] = in;
            out[i][j] = s[i][j] + D[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            ans = max(ans, s[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}