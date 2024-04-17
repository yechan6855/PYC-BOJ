#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> scores(N);
    int maxScore = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }
    }

    double newAverage = 0.0;
    for (int i = 0; i < N; i++) {
        newAverage += static_cast<double>(scores[i]) / maxScore * 100;
    }
    newAverage /= N;

    cout << fixed;
    cout.precision(9);
    cout<<newAverage << endl;

    return 0;
}