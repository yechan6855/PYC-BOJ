#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

struct Point {
    int x, y;
};

struct Segment {
    Point p1, p2;
};

int find(vector<int>& parent, int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent, parent[a]);
}

void unite(vector<int>& parent, vector<int>& rank, int a, int b) {
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    if (rootA != rootB) {
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

int ccw(Point a, Point b, Point c) {
    long long area = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
    if (area > 0) return 1;
    if (area < 0) return -1;
    return 0;
}

bool intersect(Segment s1, Segment s2) {
    int ccw1 = ccw(s1.p1, s1.p2, s2.p1);
    int ccw2 = ccw(s1.p1, s1.p2, s2.p2);
    int ccw3 = ccw(s2.p1, s2.p2, s1.p1);
    int ccw4 = ccw(s2.p1, s2.p2, s1.p2);

    if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) {
        if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0) {
            if (min(s1.p1.x, s1.p2.x) <= max(s2.p1.x, s2.p2.x) &&
                min(s2.p1.x, s2.p2.x) <= max(s1.p1.x, s1.p2.x) &&
                min(s1.p1.y, s1.p2.y) <= max(s2.p1.y, s2.p2.y) &&
                min(s2.p1.y, s2.p2.y) <= max(s1.p1.y, s1.p2.y)) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Segment> segments(N);
    vector<int> parent(N), rank(N, 0);
    for (int i = 0; i < N; ++i) {
        parent[i] = i;
        cin >> segments[i].p1.x >> segments[i].p1.y >> segments[i].p2.x >> segments[i].p2.y;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (intersect(segments[i], segments[j])) {
                unite(parent, rank, i, j);
            }
        }
    }

    vector<int> group(N, 0);
    int Groups = 0, Max = 0;
    for (int i = 0; i < N; ++i) {
        int root = find(parent, i);
        if (group[root] == 0) {
            Groups++;
        }
        group[root]++;
        Max = max(Max, group[root]);
    }

    cout << Groups << endl << Max << endl;

    return 0;
}