#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int count5 = N / 5;
    
    while (count5 >= 0) {
        int remain = N - (5 * count5);
        if (remain % 3 == 0) {
            cout << count5 + (remain / 3) << '\n';
            return 0;
        }
        count5--;
    }

    cout << "-1\n";

    return 0;
}