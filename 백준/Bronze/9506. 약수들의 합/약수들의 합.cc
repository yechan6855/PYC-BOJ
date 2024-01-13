#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == -1) {
            break;
        }
        int sum = 1;
        vector<int> divisors;
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                sum += i;
                divisors.push_back(i);
            }
        }
        if (sum == n) {
            cout << n << " = 1";
            for (int i : divisors) {
                cout << " + " << i;
            }
            cout << endl;
        } else {
            cout << n << " is NOT perfect." << endl;
        }
    }
    return 0;
}
