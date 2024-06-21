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

const int MAX = 80;
int N, M;
bool seat[MAX][MAX];
bool visited[MAX][MAX];
pii con[MAX][MAX];

int dx[] = {0, 0, -1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1, -1, 1};

bool bip_match(int n, int m) {
    for (int d = 0; d < 6; d++) {
        int nn = n + dx[d], mm = m + dy[d];
        if (0 <= nn && nn < N && 0 <= mm && mm < M && !visited[nn][mm] && seat[nn][mm]) {
            visited[nn][mm] = true;
            if (con[nn][mm] == pii(-1, -1) || bip_match(con[nn][mm].fi, con[nn][mm].se)) {
                con[nn][mm] = pii(n, m);
                return true;
            }
        }
    }
    return false;
}

int main() {
    io
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        vector<string> matrix(N);
        for (int i = 0; i < N; i++) {
            cin >> matrix[i];
        }

        int ans = 0;
        memset(seat, false, sizeof(seat));
        memset(con, -1, sizeof(con));

        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (matrix[n][m] == '.') {
                    seat[n][m] = true;
                    ans++;
                }
            }
        }

        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m += 2) {
                if (seat[n][m]) {
                    memset(visited, false, sizeof(visited));
                    if (bip_match(n, m)) {
                        ans--;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}