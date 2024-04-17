#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    string num;
    while (cin >> num) {
        if (num == "0") break;

        string rev_num = num;
        reverse(rev_num.begin(), rev_num.end());

        if (num == rev_num) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}