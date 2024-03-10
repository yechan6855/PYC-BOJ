#include <iostream>

using namespace std;

int main() {
    string N;
    cin >> N;
    int sum = 0;
    int count[10] = {0,};
    for (int i = 0; i < N.size(); i++) {
        sum += N[i] - '0';
        count[N[i] - '0']++;
    }
    if (sum % 3 != 0 || count[0] == 0) {
        cout << -1;
        return 0;
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < count[i]; j++) {
            cout << i;
        }
    }
    return 0;
}