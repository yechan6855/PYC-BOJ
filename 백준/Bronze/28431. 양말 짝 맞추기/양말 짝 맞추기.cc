#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    vector<int> socks(10, 0);
    int sock;

    for (int i = 0; i < 5; i++) {
        cin >> sock;
        socks[sock]++;
    }

    for (int i = 0; i < 10; i++) {
        if (socks[i] % 2 != 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}