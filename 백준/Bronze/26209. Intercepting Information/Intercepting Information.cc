#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define di deque<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main() {
    io;
    bool is = false;
    for (int i = 0; i < 8; i++) {
        int a;
        cin >> a;
        if (a == 9){
            is = true;
        }
    }

    if (is){
        cout << "F" << endl;
    } else{
        cout << "S" << endl;
    }

    return 0;
}