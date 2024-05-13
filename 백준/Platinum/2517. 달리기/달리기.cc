#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

struct Runner {
    int speed, index, originalPos;
};

void update(vector<int>& tree, int idx, int value, int n) {
    while (idx <= n) {
        tree[idx] += value;
        idx += idx & -idx;
    }
}

int query(const vector<int>& tree, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<Runner> runners(n);
    vector<int> results(n), tree(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> runners[i].speed;
        runners[i].originalPos = i + 1;
    }

    sort(runners.begin(), runners.end(), [](const Runner& a, const Runner& b) {
        return a.speed > b.speed || (a.speed == b.speed && a.originalPos < b.originalPos);
    });

    for (int i = 0; i < n; ++i) {
        int pos = runners[i].originalPos;
        int rank = query(tree, pos);
        results[pos - 1] = rank + 1;
        update(tree, pos, 1, n);
    }

    for (int rank : results) {
        cout << rank << endl;
    }

    return 0;
}