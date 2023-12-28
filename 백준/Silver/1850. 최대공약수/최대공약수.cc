#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, b;
    cin >> a >> b;
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    for (long long i = 0; i < a; ++i) {
        cout << '1';
    }
    cout << '\n';
    return 0;
}