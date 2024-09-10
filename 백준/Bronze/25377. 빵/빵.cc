#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int T = 1001;

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;

        if (A <= B) {
            T = min(T, B);
        }
    }

    if (T == 1001) {
        cout << -1 << endl;
    } else {
        cout << T << endl;
    }

    return 0;
}