#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    deque<int> dq;
    int num = 1;
    for (int i = n - 1; i >= 0; --i) {
        int order = input[i];
        switch (order) {
            case 1:
                dq.push_back(num++);
                break;
            case 2: {
                int temp = dq.back();
                dq.pop_back();
                dq.push_back(num++);
                if (temp != 0) {
                    dq.push_back(temp);
                }
                break;
            }
            default:
                dq.push_front(num++);
        }
    }

    reverse(dq.begin(), dq.end());

    for (int i = 0; i < n; ++i) {
        cout << dq[i] << " ";
    }
    cout << "\n";

    return 0;
}