#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define as assign
#define pi pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int MAX = LLONG_MAX;

void pad(string &a, string &b) {
    if (a.length() < b.length()) swap(a, b);
    while (a.length() != b.length()) b = '0' + b;
}

string add(const string &a, const string &b) {
    string result = "";
    bool carry = false;
    for (int i = a.length() - 1; i >= 0; --i) {
        int t1 = a[i] == '1' ? 1 : 0;
        int t2 = b[i] == '1' ? 1 : 0;
        int sum = t1 + t2 + carry;

        if (sum == 3) {
            result = '1' + result;
            carry = true;
        } else if (sum == 2) {
            result = '0' + result;
            carry = true;
        } else if (sum == 1) {
            result = '1' + result;
            carry = false;
        } else {
            result = '0' + result;
            carry = false;
        }
    }

    if (carry) result = '1' + result;
    return result;
}

string solve(const string &result) {
    size_t first_one = result.find_first_not_of('0');
    if (first_one == string::npos) return "0";
    return result.substr(first_one);
}

int32_t main() {
    string a, b;
    cin >> a >> b;

    pad(a, b);
    string res = add(a, b);
    string ans = solve(res);

    cout << ans << endl;
    return 0;
}