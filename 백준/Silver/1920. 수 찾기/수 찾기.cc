#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << binary_search(a.begin(), a.end(), x) << '\n';
    }
}