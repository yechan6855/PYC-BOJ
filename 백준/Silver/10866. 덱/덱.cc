#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> dq;
    string command;
    int number;

    while (N--) {
        cin >> command;
        if (command == "push_front") {
            cin >> number;
            dq.push_front(number);
        } else if (command == "push_back") {
            cin >> number;
            dq.push_back(number);
        } else if (command == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front() << "\n";
                dq.pop_front();
            } else {
                cout << "-1\n";
            }
        } else if (command == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back() << "\n";
                dq.pop_back();
            } else {
                cout << "-1\n";
            }
        } else if (command == "size") {
            cout << dq.size() << "\n";
        } else if (command == "empty") {
            cout << dq.empty() << "\n";
        } else if (command == "front") {
            if (!dq.empty()) {
                cout << dq.front() << "\n";
            } else {
                cout << "-1\n";
            }
        } else if (command == "back") {
            if (!dq.empty()) {
                cout << dq.back() << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
    return 0;
}