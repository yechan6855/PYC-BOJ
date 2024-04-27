#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        multiset<int> pq;

        for (int i = 0; i < k; i++) {
            char op;
            int num;
            cin >> op >> num;

            if (op == 'I') {
                pq.insert(num);
            } else if (op == 'D') {
                if (!pq.empty()) {
                    if (num == 1) {
                        auto it = pq.end();
                        it--;
                        pq.erase(it);
                    } else if (num == -1) {
                        pq.erase(pq.begin());
                    }
                }
            }
        }

        if (pq.empty()) {
            cout << "EMPTY" << endl;
        } else {
            auto max_it = pq.end();
            max_it--;
            cout << *max_it << " " << *pq.begin() << endl;
        }
    }

    return 0;
}