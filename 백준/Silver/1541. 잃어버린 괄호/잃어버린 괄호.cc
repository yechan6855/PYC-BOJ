#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> num;
    vector<char> op;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            num.push_back(stoi(temp));
            temp = "";
            op.push_back(s[i]);
        } else {
            temp += s[i];
        }
    }
    num.push_back(stoi(temp));
    int ans = num[0];
    bool minus = false;
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == '-') {
            minus = true;
        }
        if (minus) {
            ans -= num[i + 1];
        } else {
            ans += num[i + 1];
        }
    }
    cout << ans;
}