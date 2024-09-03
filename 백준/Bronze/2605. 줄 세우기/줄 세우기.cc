#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        l.insert(l.end() - num, i + 1);
    }

    for (int i = 0; i < n; i++) {
        cout << l[i] << " ";
    }

    return 0;
}