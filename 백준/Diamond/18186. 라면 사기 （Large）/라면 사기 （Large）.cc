#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main() {
    int N, B, C;
    cin >> N >> B >> C;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll cost = 0;

    if (B * 3 <= B + 2 * C) {
        for (int i = 0; i < N; i++) {
            cost += (ll)A[i] * B;
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            if (i + 2 < N) {
                if (B * 2 > B + C) {
                    int diff = A[i + 1] - A[i + 2];
                    if (diff > 0) {
                        int count = min(A[i], diff);
                        cost += (ll)count * (B + C);
                        A[i] -= count;
                        A[i + 1] -= count;
                    }
                    int count = min(A[i], min(A[i + 1], A[i + 2]));
                    cost += (ll)count * (B + 2 * C);
                    A[i] -= count;
                    A[i + 1] -= count;
                    A[i + 2] -= count;
                }
                else {
                    int diff = A[i + 1] - A[i + 2];
                    if (diff > 0) {
                        int count = min(A[i], diff);
                        cost += (ll)count * (B * 2);
                        A[i] -= count;
                        A[i + 1] -= count;
                    }
                    int count = min(A[i], min(A[i + 1], A[i + 2]));
                    cost += (ll)count * (B + 2 * C);
                    A[i] -= count;
                    A[i + 1] -= count;
                    A[i + 2] -= count;
                }
            }
            if (i + 1 < N) {
                if (B * 2 > B + C) {
                    int count = min(A[i], A[i + 1]);
                    cost += (ll) count * (B + C);
                    A[i] -= count;
                    A[i + 1] -= count;
                }
                else {
                    int count = min(A[i], A[i + 1]);
                    cost += (ll)count * (B * 2);
                    A[i] -= count;
                    A[i + 1] -= count;
                }
            }
            cost += (ll)A[i] * B;
        }
    }
    cout << cost << endl;
    return 0;
}