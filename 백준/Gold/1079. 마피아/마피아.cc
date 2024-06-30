#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define qi queue<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int N, eunjin;
vi guilty;
vvi R;
vector<bool> dead;
int max_night = 0;

void dfs(int alive, int night) {
    if (alive % 2 == 0) {
        if (dead[eunjin]) {
            max_night = max(max_night, night);
            return;
        }
        for (int i = 0; i < N; i++) {
            if (i != eunjin && !dead[i]) {
                dead[i] = true;
                for (int j = 0; j < N; j++) {
                    if (!dead[j]) guilty[j] += R[i][j];
                }
                dfs(alive - 1, night + 1);
                for (int j = 0; j < N; j++) {
                    if (!dead[j]) guilty[j] -= R[i][j];
                }
                dead[i] = false;
            }
        }
    } else {
        if (dead[eunjin]) {
            max_night = max(max_night, night);
            return;
        }
        int max_guilty = -1, victim = -1;
        for (int i = 0; i < N; i++) {
            if (!dead[i] && guilty[i] > max_guilty) {
                max_guilty = guilty[i];
                victim = i;
            }
        }
        dead[victim] = true;
        dfs(alive - 1, night);
        dead[victim] = false;
    }
}

int32_t main() {
    cin >> N;
    guilty.resize(N);
    R.resize(N, vi(N));
    dead.resize(N, false);

    for (int i = 0; i < N; i++) {
        cin >> guilty[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> R[i][j];
        }
    }

    cin >> eunjin;

    dfs(N, 0);

    cout << max_night << endl;

    return 0;
}