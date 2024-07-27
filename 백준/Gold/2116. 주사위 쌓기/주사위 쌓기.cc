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
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int opposite(int side) {
    switch(side) {
        case 0: return 5;
        case 1: return 3;
        case 2: return 4;
        case 3: return 1;
        case 4: return 2;
        case 5: return 0;
    }
    return -1;
}

int main() {
    io;
    int n;
    cin >> n;

    vvi dice(n, vi(6));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> dice[i][j];
        }
    }

    int max_sum = 0;

    for (int bottom = 0; bottom < 6; bottom++) {
        int cur_sum = 0;
        int cur_bottom = bottom;

        for (int i = 0; i < n; i++) {
            int cur_top = opposite(cur_bottom);
            int max_side = 0;

            for (int j = 0; j < 6; j++) {
                if (j != cur_bottom && j != cur_top) {
                    max_side = max(max_side, dice[i][j]);
                }
            }

            cur_sum += max_side;

            if (i < n - 1) {
                for (int j = 0; j < 6; j++) {
                    if (dice[i+1][j] == dice[i][cur_top]) {
                        cur_bottom = j;
                        break;
                    }
                }
            }
        }

        max_sum = max(max_sum, cur_sum);
    }

    cout << max_sum << endl;

    return 0;
}