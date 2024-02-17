#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> devices(N);
    for (int i = 0; i < N; ++i) {
        cin >> devices[i];
    }

    sort(devices.begin(), devices.end(), greater<int>());

    priority_queue<int> outlets;
    for (int i = 0; i < M; ++i) {
        outlets.push(0);
    }

    for (int i = 0; i < N; ++i) {
        int outlet_time = outlets.top();
        outlets.pop();
        outlets.push(outlet_time - devices[i]);
    }

    int min_time = 0;
    while (!outlets.empty()) {
        min_time = outlets.top();
        outlets.pop();
    }
    cout << -min_time << endl;

    return 0;
}