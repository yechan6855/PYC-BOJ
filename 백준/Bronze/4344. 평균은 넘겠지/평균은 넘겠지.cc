#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int C;
    cin >> C;

    while (C--) {
        int N;
        cin >> N;
        vector<int> scores(N);
        int sum = 0;

        for (int i = 0; i < N; ++i) {
            cin >> scores[i];
            sum += scores[i];
        }

        double average = static_cast<double>(sum) / N;
        int count = 0;

        for (int i = 0; i < N; ++i) {
            if (scores[i] > average) {
                ++count;
            }
        }

        double percentage = static_cast<double>(count) / N * 100;
        cout << fixed << setprecision(3) << percentage << "%" << endl;
    }

    return 0;
}