#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define endl "\n"
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define io ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

class Shark {
public:
    int a, b, c;
    Shark() : a(0),b(0),c(0){}
    Shark(int a, int b, int c) : a(a), b(b), c(c) {}
    bool canEat(const Shark& ano) const {
        return a >= ano.a && b >= ano.b && c >= ano.c;
    }
};

int* matched;
bool* v;
vi* edges;
int n;

bool matching(int from) {
    for (int to : edges[from]) {
        if (v[to]) continue;
        v[to] = true;
        if (matched[to] == -1 || matching(matched[to])) {
            matched[to] = from;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    edges = new vi[n];
    matched = new int[n];
    fill(matched, matched + n, -1);

    Shark* arr = new Shark[n];
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = Shark(a, b, c);
        for (int j = 0; j < i; ++j) {
            if (arr[i].canEat(arr[j]) && arr[j].canEat(arr[i])) edges[i].push_back(j);
            else if (arr[i].canEat(arr[j])) edges[i].push_back(j);
            else if (arr[j].canEat(arr[i])) edges[j].push_back(i);
        }
    }

    int cnt = 0;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < n; ++i) {
            v = new bool[n];
            memset(v, false, n * sizeof(bool));
            if (matching(i)) {
                ++cnt;
            }
            delete[] v;
        }
    }

    cout << n - cnt << endl;

    delete[] arr;
    delete[] edges;
    delete[] matched;
}

int main() {
    io;
    solve();
    return 0;
}