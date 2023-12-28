#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    while (n--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (minHeap.empty()) {
                cout << "0\n";
            } else {
                cout << minHeap.top() << "\n";
                minHeap.pop();
            }
        } else {
            minHeap.push(x);
        }
    }

    return 0;
}
