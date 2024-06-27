#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

void solve(int n, int f, vi &cnt) {
    while (n > 0) {
        cnt[n % 10] += f;
        n /= 10;
    }
}

int32_t main() {
    io;
    int N;
    cin >> N;

    vi counts(10, 0);
    int start = 1;
    int factor = 1;

    while (start <= N) {
        while (start % 10 != 0 && start <= N) {
            solve(start, factor, counts);
            start++;
        }
        if (start > N) break;
        while (N % 10 != 9 && start <= N) {
            solve(N, factor, counts);
            N--;
        }

        int startDiv10 = start / 10;
        int endDiv10 = N / 10;
        for (int i = 0; i < 10; i++) {
            counts[i] += (endDiv10 - startDiv10 + 1) * factor;
        }

        factor *= 10;
        start /= 10;
        N /= 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << counts[i] << " ";
    }
    cout << endl;

    return 0;
}