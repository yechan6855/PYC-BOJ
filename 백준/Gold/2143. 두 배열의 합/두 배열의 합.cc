#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long T;
    cin >> T;

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int m;
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    vector<long long> sumA, sumB;

    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        for (int j = i; j < n; ++j) {
            sum += A[j];
            sumA.push_back(sum);
        }
    }

    for (int i = 0; i < m; ++i) {
        long long sum = 0;
        for (int j = i; j < m; ++j) {
            sum += B[j];
            sumB.push_back(sum);
        }
    }

    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());

    long long result = 0;
    for (int i = 0; i < sumA.size(); ++i) {
        long long target = T - sumA[i];
        auto range = equal_range(sumB.begin(), sumB.end(), target);
        result += range.second - range.first;
    }

    cout << result << endl;

    return 0;
}