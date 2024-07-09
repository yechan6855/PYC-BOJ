#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

string solve(int n) {
    if (n % 3 == 0 && n % 5 == 0) {
        return "FizzBuzz";
    } else if (n % 3 == 0) {
        return "Fizz";
    } else if (n % 5 == 0) {
        return "Buzz";
    } else {
        return to_string(n);
    }
}

int32_t main() {
    string s[3];
    for (int i = 0; i < 3; ++i) {
        getline(cin, s[i]);
    }

    for (int i = 2; i >= 0; --i) {
        try {
            int n = stoi(s[i]) + (3 - i);
            cout << solve(n) << endl;
            return 0;
        } catch (invalid_argument& e){}
    }
}