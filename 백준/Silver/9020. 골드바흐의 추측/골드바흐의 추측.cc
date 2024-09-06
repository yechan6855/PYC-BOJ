#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<bool> sieve(10001, true);

void eratosthenes() {
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= sqrt(10000); i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= 10000; j += i) {
                sieve[j] = false;
            }
        }
    }
}

void goldbach(int n) {
    for (int i = n / 2; i >= 2; i--) {
        if (sieve[i] && sieve[n - i]) {
            cout << i << " " << n - i << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    eratosthenes();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        goldbach(n);
    }

    return 0;
}