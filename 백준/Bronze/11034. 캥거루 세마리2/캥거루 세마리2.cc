#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;

    while (cin >> A >> B >> C) {
        int gap1 = B - A - 1;
        int gap2 = C - B - 1;

        cout << max(gap1, gap2) << endl;
    }

    return 0;
}