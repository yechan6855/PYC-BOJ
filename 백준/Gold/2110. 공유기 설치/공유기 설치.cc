#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

bool solve(const vector<int>& houses, int n, int c, int minDist) {
    int count = 1;
    int lastInstalled = houses[0];

    for (int i = 1; i < n; ++i) {
        if (houses[i] - lastInstalled >= minDist) {
            count++;
            lastInstalled = houses[i];
        }
        if (count >= c) return true;
    }
    return false;
}

int main() {
    io;
    int n, c;
    cin >> n >> c;

    vector<int> houses(n);
    for (int i = 0; i < n; ++i) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    int low = 1;
    int high = houses[n-1] - houses[0];
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (solve(houses, n, c, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}