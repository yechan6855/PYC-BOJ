#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define MOD 1000000007
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct FenwickTree {
    vi tree;

    FenwickTree(int n) : tree(n + 1, 1e9) {}

    void update(int idx, int value) {
        while (idx < tree.size()) {
            tree[idx] = min(tree[idx], value);
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int result = 1e9;
        while (idx > 0) {
            result = min(result, tree[idx]);
            idx -= idx & -idx;
        }
        return result;
    }
};

int main() {
    io;
    int N;
    cin >> N;

    vi exam1(N), exam2(N), exam3(N);
    vi rank1(N), rank2(N), rank3(N);

    for (int i = 0; i < N; ++i) {
        cin >> exam1[i];
        rank1[exam1[i] - 1] = i + 1;
    }
    for (int i = 0; i < N; ++i) {
        cin >> exam2[i];
        rank2[exam2[i] - 1] = i + 1;
    }
    for (int i = 0; i < N; ++i) {
        cin >> exam3[i];
        rank3[exam3[i] - 1] = i + 1;
    }

    vector<tuple<int, int, int>> students(N);
    for (int i = 0; i < N; ++i) {
        students[i] = make_tuple(rank1[i], rank2[i], rank3[i]);
    }

    sort(students.begin(), students.end());

    FenwickTree fenwick(N);
    int ans = 0;

    for (auto& [r1, r2, r3] : students) {
        int min = fenwick.query(r2);
        if (min > r3) {
            ans++;
        }
        fenwick.update(r2, r3);
    }
    cout << ans << endl;

    return 0;
}