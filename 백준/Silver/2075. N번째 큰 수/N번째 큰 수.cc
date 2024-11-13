#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;

            if(x > pq.top()) {
                pq.pop();
                pq.push(x);
            }
        }
    }

    cout << pq.top() << '\n';

    return 0;
}