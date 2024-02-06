#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, less<int>> maxHeap;  // 최대 힙
    priority_queue<int, vector<int>, greater<int>> minHeap;  // 최소 힙

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        if (maxHeap.empty() || maxHeap.top() >= num)
            maxHeap.push(num);
        else
            minHeap.push(num);

        // 최대 힙과 최소 힙의 크기 조절
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.top() << '\n';
    }

    return 0;
}