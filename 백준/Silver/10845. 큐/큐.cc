#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    queue<int> q;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string order;
        getline(cin, order);
        if (order == "pop") {
            if (q.empty()) cout << -1 << endl;
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (order == "size") {
            cout << q.size() << endl;
        }
        else if (order == "empty") {
            if (q.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (order == "front") {
            if (q.empty()) cout << -1 << endl;
            else
                cout << q.front() << endl;
        }
        else if (order == "back") {
            if (q.empty()) cout << -1 << endl;
            else
                cout << q.back() << endl;
        }
        else {
            order = order.erase(0, 5);
            int x = stoi(order);
            q.push(x);
        }
    }
}