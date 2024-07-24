#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int N, K;
vector<string> nums;
vector<int> remainders;
vector<vector<ll>> dp;
vector<int> pow_mod;

int mod(string& s, int m) {
    int ret = 0;
    for (char c : s)
        ret = (ret * 10 + (c - '0')) % m;
    return ret;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    io;
    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    cin >> K;

    remainders.resize(N);
    for (int i = 0; i < N; i++)
        remainders[i] = mod(nums[i], K);

    pow_mod.resize(51);
    pow_mod[0] = 1 % K;
    for (int i = 1; i <= 50; i++)
        pow_mod[i] = (pow_mod[i-1] * 10) % K;

    dp.resize(1 << N, vector<ll>(K, 0));
    dp[0][0] = 1;

    for (int mask = 0; mask < (1 << N); mask++) {
        for (int rem = 0; rem < K; rem++) {
            for (int i = 0; i < N; i++) {
                if (!(mask & (1 << i))) {
                    int next_mask = mask | (1 << i);
                    int next_rem = (rem * pow_mod[nums[i].length()] + remainders[i]) % K;
                    dp[next_mask][next_rem] += dp[mask][rem];
                }
            }
        }
    }

    ll p = dp[(1 << N) - 1][0];
    ll q = 1;
    for (int i = 2; i <= N; i++)
        q *= i;

    if (p == 0) {
        cout << "0/1" << endl;
    } else {
        ll g = gcd(p, q);
        cout << p/g << "/" << q/g << endl;
    }

    return 0;
}