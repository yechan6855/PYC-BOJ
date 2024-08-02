#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

typedef vector<vector<long long>> matrix;
const int MOD = 1000;

matrix multiply(const matrix& a, const matrix& b) {
    int n = a.size();
    matrix result(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= MOD;
        }
    }
    return result;
}

matrix power(matrix a, long long b) {
    int n = a.size();
    matrix result(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }

    while (b > 0) {
        if (b & 1) {
            result = multiply(result, a);
        }
        a = multiply(a, a);
        b >>= 1;
    }

    return result;
}

int main() {
    io;
    int N;
    long long B;
    cin >> N >> B;

    matrix A(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            A[i][j] %= MOD;
        }
    }

    matrix result = power(A, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}