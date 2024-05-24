#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long D, P, Q;
    cin >> D >> P >> Q;

    if (P < Q) swap(P, Q);

    long long answer = LLONG_MAX;


    for (long long a = 0; a <= Q; ++a) {
        long long remaining = D - a * P;
        if (remaining <= 0) {
            answer = min(answer, a * P);
            break;
        }
        long long b = (remaining + Q - 1) / Q;
        answer = min(answer, a * P + b * Q);
    }

    cout << answer << endl;
    return 0;
}