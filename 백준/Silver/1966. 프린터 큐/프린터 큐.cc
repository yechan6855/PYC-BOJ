#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define di deque<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> a(N);
        queue<int> b;

        for (int i = 0; i < N; ++i) {
            cin >> a[i];
            b.push(i);
        }

        int printOrder = 0;

        while (!b.empty()) {
            int idx = b.front();
            b.pop();

            bool isHighest = true;
            for (int i = 0; i < N; ++i) {
                if (a[i] > a[idx]) {
                    isHighest = false;
                    break;
                }
            }

            if (isHighest) {
                ++printOrder;
                a[idx] = 0;
                if (idx == M) {
                    cout << printOrder << endl;
                    break;
                }
            } else {
                b.push(idx);
            }
        }
    }

    return 0;
}