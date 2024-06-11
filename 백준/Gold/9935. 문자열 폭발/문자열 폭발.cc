#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    io;
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<char> stack;
    int idx = 0;

    while (stack.size() < s2.size()) {
        stack.pb(s1[idx]);
        idx++;
    }

    while (idx < s1.size()) {
        if (stack.size() >= s2.size()) {
            bool able = true;
            for (int i = 0; i < s2.size(); i++) {
                if (stack[stack.size() - s2.size() + i] != s2[i]) {
                    able = false;
                    break;
                }
            }
            if (able) {
                for (int i = 0; i < s2.size(); i++) {
                    stack.pob();
                }
            }
        }
        stack.pb(s1[idx]);
        idx++;
    }

    bool able = true;
    for (int i = 0; i < s2.size(); i++) {
        if (stack[stack.size() - s2.size() + i] != s2[i]) {
            able = false;
            break;
        }
    }
    if (able) {
        for (int i = 0; i < s2.size(); i++) {
            stack.pob();
        }
    }

    if (stack.empty()) {
        cout << "FRULA" << endl;
    } else {
        for (char c : stack) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}