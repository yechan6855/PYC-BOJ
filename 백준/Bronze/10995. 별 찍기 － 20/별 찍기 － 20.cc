#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 1) {
            cout << " ";
        }

        for (int j = 0; j < N; j++) {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}