#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

const int MAX_N = 300005;
const int MAX_C = 10005;

int n, c, m;
int arr[MAX_N];
vector<int> pos[MAX_C];

bool check(int l, int r, int color) {
    int cnt = upper_bound(pos[color].begin(), pos[color].end(), r) -
              lower_bound(pos[color].begin(), pos[color].end(), l);
    return cnt > (r - l + 1) / 2;
}

int main() {
    io;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        bool found = false;
        for (int i = 0; i < 20; i++) {
            int color = arr[l + rand() % (r - l + 1)];
            if (check(l, r, color)) {
                cout << "yes " << color << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "no" << endl;
        }
    }

    return 0;
}