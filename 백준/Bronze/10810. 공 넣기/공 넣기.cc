#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> basket(N, 0);

    for (int i = 0; i < M; i++) {
        int start, end, num;
        cin >> start >> end >> num;

        for (int j = start - 1; j < end; j++) {
            if (basket[j] != num) {
                basket[j] = num;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << basket[i] << " ";
    }
    cout << endl;

    return 0;
}