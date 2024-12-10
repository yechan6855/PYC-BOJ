#include <iostream>
using namespace std;

char solve(int x) {
    int p = 3;
    int r = (x - 1) % p;

    switch(r) {
        case 0: return 'U';
        case 1: return 'O';
        case 2: return 'S';
    }

    return 'U';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    cout << solve(x);

    return 0;
}