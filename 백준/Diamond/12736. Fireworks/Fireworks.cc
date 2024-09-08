#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, x2;
    cin >> x1 >> x2;

    vector<int> p(x1 + x2), len(x1 + x2);
    for (int z = 1; z < x1 + x2; ++z) {
        cin >> p[z] >> len[z];
        --p[z];
    }

    vector<int> s(x1 + x2);
    vector<ll> res(x1 + x2);
    vector<priority_queue<ll>> heap(x1 + x2);

    for (int z = x1 + x2 - 1; z >= 0; --z) {
        if (z >= x1) {
            s[z] = 1;
            heap[z].push(len[z]);
            heap[z].push(len[z]);
        } else {
            while (s[z] > 1) {
                ll topVal = heap[z].top();
                heap[z].pop();
                res[z] -= --s[z] * (topVal - heap[z].top());
            }

            ll a = heap[z].top() + len[z];
            heap[z].pop();
            ll b = heap[z].top() + len[z];
            heap[z].pop();
            heap[z].push(a);
            heap[z].push(b);
        }

        if (z == 0) {
            cout << res[z] << '\n';
            return 0;
        }

        if (heap[p[z]].size() < heap[z].size()) {
            heap[p[z]].swap(heap[z]);
            swap(s[p[z]], s[z]);
            swap(res[p[z]], res[z]);
        }

        if (heap[z].empty()) continue;

        res[p[z]] += res[z] + (heap[p[z]].top() > heap[z].top() ? s[z] * (heap[p[z]].top() - heap[z].top()) : s[p[z]] * (heap[z].top() - heap[p[z]].top()));
        s[p[z]] += s[z];

        while (!heap[z].empty()) {
            heap[p[z]].push(heap[z].top());
            heap[z].pop();
        }
    }

    return 0;
}