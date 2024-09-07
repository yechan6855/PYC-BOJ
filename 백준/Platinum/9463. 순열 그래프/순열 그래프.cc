#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 100001;

int n;
vector<int> fenwick_tree(MAX_N, 0);

void update(int i, int val) {
    while (i <= n) {
        fenwick_tree[i] += val;
        i += (i & -i);
    }
}

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += fenwick_tree[i];
        i -= (i & -i);
    }
    return sum;
}

ll solve() {
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }

    ll result = 0;
    fill(fenwick_tree.begin(), fenwick_tree.end(), 0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int p = pos[x];
        result += i - 1 - query(p);
        update(p, 1);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << solve() << '\n';
    }

    return 0;
}