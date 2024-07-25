#include <bits/stdc++.h>
#define endl "\n"
#define vi vector<int>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    io;
    int n, m;
    cin >> n >> m;

    vi a(n);
    vi b(m);
    vi ans(n + m);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin());

    for(int num : ans) {
        cout << num << ' ';
    }

    return 0;
}