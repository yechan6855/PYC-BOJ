#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl "\n"
using namespace std;

ull power(ull a, ull b, ull mod) {
    ull ret = 1;
    a = a % mod;
    while (b > 0) {
        if (b & 1) {
            ret = (ret * a) % mod;
        }
        b = b >> 1;
        a = (a * a) % mod;
    }
    return ret;
}

bool solve(ull n, ull a) {
    ull r = 0;
    ull d = n - 1;
    while (d % 2 == 0) {
        r++;
        d = d >> 1;
    }
    ull x = power(a, d, n);
    if (x == 1 || x == n - 1) return true;
    for (int i = 0; i < r - 1; i++) {
        x = power(x, 2, n);
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrime(ull n) {
    ull alist[5] = { 2, 3, 5, 7, 11 };
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 0; i < 5; i++) {
        ull a = alist[i];
        if (n == a) return true;
        if (!solve(n, a)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int cnt = 0;
    while (t--) {
        ull n;
        cin >> n;
        if (isPrime(2 * n + 1)) cnt++;
    }

    cout << cnt << endl;

    return 0;
}