#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    set<int> s;
    map<int, int> heights;

    long long result = 0;

    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;

        auto it = s.lower_bound(value);

        int leftHeight = (it == s.begin()) ? 0 : heights[*prev(it)];
        int rightHeight = (it == s.end()) ? 0 : heights[*it];

        int currentHeight = 1 + max(leftHeight, rightHeight);
        result += currentHeight;

        s.insert(value);
        heights[value] = currentHeight;
    }
    cout << result << endl;

    return 0;
}