#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> comp(const vector<int>& pat) {
    int m = pat.size();
    vector<int> pi(m);
    pi[0] = 0;
    int k = 0;
    for (int q = 1; q < m; ++q) {
        while (k > 0 && pat[k] != pat[q]) {
            k = pi[k - 1];
        }
        if (pat[k] == pat[q]) {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}

bool solve(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;

    vector<int> ext_b = b;
    ext_b.insert(ext_b.end(), b.begin(), b.end());

    vector<int> pi = comp(a);

    int n = a.size();
    int q = 0;
    for (int i = 0; i < 2 * n - 1; ++i) {
        while (q > 0 && a[q] != ext_b[i]) {
            q = pi[q - 1];
        }
        if (a[q] == ext_b[i]) {
            q++;
        }
        if (q == n) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    if (solve(a, b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}