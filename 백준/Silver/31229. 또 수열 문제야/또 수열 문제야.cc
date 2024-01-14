#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> result;
    int current = 1;

    for (int i = 0; i < N; ++i) {
        result.push_back(current);
        current += 2;
    }

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}