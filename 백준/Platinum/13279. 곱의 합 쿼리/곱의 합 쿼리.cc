#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 100003;

vector<ll> add(const vector<ll> &A, const vector<ll> &B) {
    int n = max(A.size(), B.size());
    vector<ll> C(n, 0);
    for(int i = 0; i < n; ++i){
        if(i < A.size()) C[i] += A[i];
        if(i < B.size()) C[i] += B[i];
        C[i] %= MOD;
    }
    return C;
}

vector<ll> subtract(const vector<ll> &A, const vector<ll> &B){
    int n = max(A.size(), B.size());
    vector<ll> C(n, 0);
    for(int i = 0; i < n; ++i){
        if(i < A.size()) C[i] += A[i];
        if(i < B.size()) C[i] -= B[i];
        C[i] = (C[i] % MOD + MOD) % MOD;
    }
    return C;
}

vector<ll> karatsuba(const vector<ll> &A, const vector<ll> &B){
    int n = A.size();
    int m = B.size();

    if(n == 0 || m == 0){
        return {};
    }
    if(min(n, m) <= 32){
        vector<ll> C(n + m -1, 0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                C[i+j] += (A[i] * B[j]) % MOD;
                C[i+j] %= MOD;
            }
        }
        return C;
    }

    int k = n / 2;

    vector<ll> A_low(A.begin(), A.begin() + min(k, n));
    vector<ll> A_high(A.begin() + min(k, n), A.end());

    vector<ll> B_low(B.begin(), B.begin() + min(k, m));
    vector<ll> B_high(B.begin() + min(k, m), B.end());

    vector<ll> Z0 = karatsuba(A_low, B_low);
    vector<ll> Z2 = karatsuba(A_high, B_high);
    vector<ll> A_sum = add(A_low, A_high);
    vector<ll> B_sum = add(B_low, B_high);
    vector<ll> Z1 = karatsuba(A_sum, B_sum);

    Z1 = subtract(Z1, Z0);
    Z1 = subtract(Z1, Z2);

    vector<ll> C(max((int)Z0.size(), (int)Z2.size() + 2*k), 0);
    for(int i = 0; i < Z0.size(); ++i){
        C[i] += Z0[i];
        C[i] %= MOD;
    }
    for(int i = 0; i < Z1.size(); ++i){
        C[i + k] += Z1[i];
        C[i + k] %= MOD;
    }
    for(int i = 0; i < Z2.size(); ++i){
        C[i + 2*k] += Z2[i];
        C[i + 2*k] %= MOD;
    }
    return C;
}

vector<ll> multiply(vector<ll> a, vector<ll> b) {
    return karatsuba(a, b);
}

vector<ll> prod(vector<ll> &A, int l, int r) {
    if (l == r) {
        return {1, A[l] % MOD};
    }
    int mid = (l + r) / 2;
    vector<ll> left = prod(A, l, mid);
    vector<ll> right = prod(A, mid + 1, r);
    vector<ll> product = multiply(left, right);

    return product;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> A(N);

    for (auto &x: A) {
        cin >> x;
        x %= MOD;
    }

    vector<ll> poly = prod(A, 0, N - 1);

    int q;
    cin >> q;

    while (q--) {
        int K;
        cin >> K;

        if (K >= poly.size()) {
            cout << "0\n";
        } else {
            cout << (poly[K] % MOD) << "\n";
        }
    }
}