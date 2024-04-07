#include <bits/stdc++.h>

using namespace std;

bool compareNumbers(const string& a, const string& b) {
    return a + b > b + a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end(), compareNumbers);

    if (numbers[0] == "0") {
        cout << "0";
    } else {
        for (const auto& num : numbers) {
            cout << num;
        }
    }

    return 0;
}