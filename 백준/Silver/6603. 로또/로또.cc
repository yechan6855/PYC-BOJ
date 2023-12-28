#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateCombinations(vector<int>& lotto, vector<int>& numbers, int index, int count) {
    if (count == 6) {
        for (int num : lotto) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = index; i < numbers.size(); ++i) {
        lotto[count] = numbers[i];
        generateCombinations(lotto, numbers, i + 1, count + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int k;
        cin >> k;

        if (k == 0) {
            break;
        }

        vector<int> numbers(k);
        vector<int> lotto(6);

        for (int i = 0; i < k; ++i) {
            cin >> numbers[i];
        }

        generateCombinations(lotto, numbers, 0, 0);
        cout << "\n";
    }

    return 0;
}