#include <iostream>

using namespace std;

long long power(int A, int B, int C) {
    if (B == 0) {
        return 1;
    }

    long long halfPower = power(A, B / 2, C);
    long long result = (halfPower * halfPower) % C;

    if (B % 2 == 1) {
        return (result * A) % C;
    } else {
        return result;
    }
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    long long result = power(A, B, C);

    cout << result << endl;

    return 0;
}
