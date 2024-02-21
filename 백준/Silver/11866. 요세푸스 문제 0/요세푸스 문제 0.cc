#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    cout << "<";
    int idx = 0;
    while (!v.empty()) {
        idx = (idx + k - 1) % v.size();
        cout << v[idx];
        v.erase(v.begin() + idx);
        if (!v.empty()) {
            cout << ", ";
        }
    }
    cout << ">";
    return 0;
}