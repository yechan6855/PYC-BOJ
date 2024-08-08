#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    priority_queue<int> pq;
    vector<int> f(n);

    for (int i = 0; i < n; ++i) {
        const int x = i - 1;
        if (pq.empty() || pq.top() + x <= arr[i]) {
            pq.push(arr[i] - x);
        } else {
            pq.pop();
            pq.push(arr[i] - x);
            pq.push(arr[i] - x);
        }
        f[i] = pq.top() + x;
    }

    for (int i = n - 2; i >= 0; --i) {
        f[i] = min(f[i], f[i + 1] - 1);
    }

    for (int y : f) {
        cout << y << '\n';
    }

    return 0;
}