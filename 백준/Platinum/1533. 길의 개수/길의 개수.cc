#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int MOD = 1000003;

vector<vector<ll>> multiply(const vector<vector<ll>>& a, const vector<vector<ll>>& b, int n) {
    vector<vector<ll>> result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

vector<vector<ll>> power(vector<vector<ll>>& matrix, int p, int n) {
    if (p == 1) return matrix;
    if (p % 2 == 0) {
        auto half = power(matrix, p / 2, n);
        return multiply(half, half, n);
    }
    auto half = power(matrix, p - 1, n);
    return multiply(half, matrix, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S, E, T;
    cin >> N >> S >> E >> T;
    S--; E--;

    vector<vector<ll>> matrix(5 * N, vector<ll>(5 * N, 0));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            int weight = row[j] - '0';
            if (weight > 0) {
                matrix[i * 5][j * 5 + weight - 1] = 1;
            }
        }
        for (int j = 1; j < 5; j++) {
            matrix[i * 5 + j][i * 5 + j - 1] = 1;
        }
    }

    auto result = power(matrix, T, 5 * N);
    cout << result[S * 5][E * 5] << endl;

    return 0;
}