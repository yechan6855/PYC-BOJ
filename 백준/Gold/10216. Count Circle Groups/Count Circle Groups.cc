#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct Circle {
    int x, y, r;
};

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

bool intersect(const Circle& a, const Circle& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int dist = dx * dx + dy * dy;
    int sum = a.r + b.r;
    return dist <= sum * sum;
}

int main() {
    io;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Circle> c(n);
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> c[i].x >> c[i].y >> c[i].r;
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(c[i], c[j])) {
                    unite(i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}