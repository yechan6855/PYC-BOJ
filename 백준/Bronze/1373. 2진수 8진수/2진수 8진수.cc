#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    string bin;
    cin >> bin;

    int len = bin.length();
    int pad = (3 - len % 3) % 3;
    bin = string(pad, '0') + bin;

    len = bin.length();
    string oct = "";

    for (int i = 0; i < len; i += 3) {
        string b3 = bin.substr(i, 3);
        int val = stoi(b3, nullptr, 2);
        oct += to_string(val);
    }

    cout << oct << endl;

    return 0;
}