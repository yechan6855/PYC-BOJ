#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> basket(N);
    for (int i = 0; i < N; i++) {
        basket[i] = i + 1;
    }

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        start--;
        end--;

        while (start < end) {
            swap(basket[start], basket[end]);
            start++;
            end--;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << basket[i] << " ";
    }
    cout << endl;

    return 0;
}