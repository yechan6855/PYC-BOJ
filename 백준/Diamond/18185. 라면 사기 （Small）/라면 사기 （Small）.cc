#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int32_t main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cost = 0;
    for (int i = 0; i < N; i++) {
        if (i+2 < N) {
            int diff = A[i+1] - A[i+2];
            if (diff > 0) {
                int count = min(A[i], diff);
                cost += count * 5;
                A[i] -= count;
                A[i+1] -= count;
            }

            int count = min(A[i], min(A[i+1], A[i+2]));
            cost += count * 7;
            A[i] -= count;
            A[i+1] -= count;
            A[i+2] -= count;
        }
        if (i+1 < N) {
            int count = min(A[i], A[i+1]);
            cost += count * 5;
            A[i] -= count;
            A[i+1] -= count;
        }
        cost += A[i] * 3;
    }

    cout << cost << endl;
    return 0;
}