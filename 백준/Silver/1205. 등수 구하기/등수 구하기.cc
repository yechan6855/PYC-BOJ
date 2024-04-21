#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    int N, newScore, P;
    cin >> N >> newScore >> P;

    vector<int> rankList(N);
    for (int i = 0; i < N; i++) {
        cin >> rankList[i];
    }

    if (N == P && newScore <= rankList.back()) {
        cout << -1 << endl;
    } else {
        auto it = lower_bound(rankList.begin(), rankList.end(), newScore, greater<int>());
        int rank = distance(rankList.begin(), it) + 1;
        cout << rank << endl;
    }
    return 0;
}