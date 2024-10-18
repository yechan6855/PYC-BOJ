#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K, M;
    cin >> N >> K >> M;

    deque<int> dq;
    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    vector<int> ans;
    bool reverse = false;
    int cnt = 0;

    while (!dq.empty()) {
        if (!reverse) {
            for (int i = 0; i < K - 1; ++i) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            ans.push_back(dq.front());
            dq.pop_front();
        } else {
            for (int i = 0; i < K - 1; ++i) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans.push_back(dq.back());
            dq.pop_back();
        }

        ++cnt;

        if (cnt % M == 0) {
            reverse = !reverse;
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}