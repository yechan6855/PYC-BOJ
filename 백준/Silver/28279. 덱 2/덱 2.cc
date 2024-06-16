#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define pii pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define di deque<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define MOD 9901
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    io;
    int t;
    cin >> t;
    di d;
    while(t--){
        int c;
        cin >> c;

        if (c == 1) {
            int x;
            cin >> x;
            d.pf(x);
        } else if (c == 2) {
            int x;
            cin >> x;
            d.pb(x);
        } else if (c == 3) {
            if (d.empty()) {
                cout << -1 << endl;
            } else {
                cout << d.front() << endl;
                d.pof();
            }
        } else if (c == 4) {
            if (d.empty()) {
                cout << -1 << endl;
            } else {
                cout << d.back() << endl;
                d.pob();
            }
        } else if (c == 5) {
            cout << d.size() << endl;
        } else if (c == 6) {
            cout << d.empty() << endl;
        } else if (c == 7) {
            if (d.empty()) {
                cout << -1 << endl;
            } else {
                cout << d.front() << endl;
            }
        } else if (c == 8) {
            if (d.empty()) {
                cout << -1 << endl;
            } else {
                cout << d.back() << endl;
            }
        }
    }
    return 0;
}