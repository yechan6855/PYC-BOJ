#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;

    int bitmask = 0;

    while (m--) {
        string op;
        cin >> op;

        if (op == "add") {
            int x;
            cin >> x;
            bitmask |= (1 << x);
        } else if (op == "remove") {
            int x;
            cin >> x;
            bitmask &= ~(1 << x);
        } else if (op == "check") {
            int x;
            cin >> x;
            int result = (bitmask & (1 << x)) ? 1 : 0;
            cout << result << "\n";
        } else if (op == "toggle") {
            int x;
            cin >> x;
            bitmask ^= (1 << x);
        } else if (op == "all") {
            bitmask = (1 << 21) - 1;
        } else if (op == "empty") {
            bitmask = 0;
        }
    }
    return 0;
}