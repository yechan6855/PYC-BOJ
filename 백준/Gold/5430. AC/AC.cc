#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        deque<int> dq;
        string arr;
        cin >> arr;

        int num = 0;
        for (char c : arr) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (num > 0) {
                dq.push_back(num);
                num = 0;
            }
        }
        bool reverse = false;
        bool error = false;

        for (char c : p) {
            if (c == 'R') {
                reverse = !reverse;
            } else if (c == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }

                if (reverse) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }
        if (error) {
            cout << "error\n";
        } else {
            cout << "[";
            while (!dq.empty()) {
                if (reverse) {
                    cout << dq.back();
                    dq.pop_back();
                } else {
                    cout << dq.front();
                    dq.pop_front();
                }

                if (!dq.empty()) {
                    cout << ",";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}