#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> sequence(N);
    for(int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    int start = 0, end = 0, sum = 0, minLength = INT_MAX;
    while(true) {
        if(sum >= S) {
            minLength = min(minLength, end - start);
            sum -= sequence[start++];
        } else if(end == N) {
            break;
        } else {
            sum += sequence[end++];
        }
    }

    if(minLength == INT_MAX) {
        cout << "0\n";
    } else {
        cout << minLength << "\n";
    }
    return 0;
}