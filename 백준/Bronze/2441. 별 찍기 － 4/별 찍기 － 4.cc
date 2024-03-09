#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int space = 0; space < i; ++space) {
            cout << " ";
        }

        for (int star = 0; star < N - i; ++star) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}