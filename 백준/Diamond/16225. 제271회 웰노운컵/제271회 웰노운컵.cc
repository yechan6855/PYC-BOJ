#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> scores[i].first;
    }

    sort(scores.begin(), scores.end());

    long long ans = 0;
    priority_queue<int> pq;

    ans += scores[0].second;

    for (int i = 1; i < n - 1; i += 2) {
        pq.push(scores[i].second);
        pq.push(scores[i+1].second);
        ans += pq.top();
        pq.pop();
    }

    cout << ans << '\n';

    return 0;
}