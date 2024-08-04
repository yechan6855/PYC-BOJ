#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    io;
    int n;
    cin >> n;

    priority_queue<int> pq;
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        pq.push(x - i + 1);

        if (!pq.empty() && pq.top() > x - i + 1) {
            ans += pq.top() - (x - i + 1);
            pq.pop();
            pq.push(x - i + 1);
        }
    }

    cout << ans << endl;

    return 0;
}