#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int MAX = 1000000;
vector<bool> isPrime(MAX + 1, true);
vector<int> primes;

void Prime() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int solve(int n) {
    int count = 0;
    for (int i = 0; primes[i] <= n / 2; i++) {
        if (isPrime[n - primes[i]]) {
            count++;
        }
    }
    return count;
}

int32_t main() {
    Prime();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}