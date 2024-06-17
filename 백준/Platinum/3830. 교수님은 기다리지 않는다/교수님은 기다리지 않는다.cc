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

const int MAX = 100001;
int parent[MAX];
long long diff[MAX];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    int p = find(parent[x]);
    diff[x] += diff[parent[x]];
    return parent[x] = p;
}

void union_sets(int a, int b, int w) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        parent[rootB] = rootA;
        diff[rootB] = diff[a] - diff[b] + w;
    }
}

int main() {
    io;
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            diff[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            string s;
            int a, b, w;
            cin >> s;

            if (s == "!") {
                cin >> a >> b >> w;
                union_sets(a, b, w);
            } else if (s == "?") {
                cin >> a >> b;
                if (find(a) == find(b)) {
                    cout << diff[b] - diff[a] << endl;
                } else {
                    cout << "UNKNOWN" << endl;
                }
            }
        }
    }

    return 0;
}