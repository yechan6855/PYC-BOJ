#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

string replaceChar(string str, char from, char to) {
    for (char &c : str) {
        if (c == from) {
            c = to;
        }
    }
    return str;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    cin >> a >> b;

    string a_min = replaceChar(a, '6', '5');
    string b_min = replaceChar(b, '6', '5');
    int min_sum = stoi(a_min) + stoi(b_min);

    string a_max = replaceChar(a, '5', '6');
    string b_max = replaceChar(b, '5', '6');
    int max_sum = stoi(a_max) + stoi(b_max);

    cout << min_sum << " " << max_sum << endl;

    return 0;
}