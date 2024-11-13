#include <iostream>
using namespace std;

int main() {
    long long A, B;

    cin >> A >> B;

    if (A > B) {
        long long temp = A;
        A = B;
        B = temp;
    }

    if (A >= B || B - A == 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << B - A - 1 << endl;

    for (long long i = A + 1; i < B; i++) {
        cout << i << " ";
    }

    return 0;
}