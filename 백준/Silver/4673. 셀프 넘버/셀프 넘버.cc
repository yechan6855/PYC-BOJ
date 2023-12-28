#include <iostream>
using namespace std;

int d(int n) {
    int sum = n;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool isSelfNumber[10001] = {false};

    for (int i = 1; i <= 10000; ++i) {
        int nextNum = d(i);
        if (nextNum <= 10000) {
            isSelfNumber[nextNum] = true;
        }
    }
    for (int i = 1; i <= 10000; ++i) {
        if (!isSelfNumber[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}
