#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0) {
        cout << "0\n";
        return 0;
    }

    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    int exclude = (int)round(n * 0.15);

    sort(scores.begin(), scores.end());

    double sum = 0;
    for (int i = exclude; i < n - exclude; i++) {
        sum += scores[i];
    }

    int result = (int)round(sum / (n - 2 * exclude));

    cout << result << "\n";

    return 0;
}