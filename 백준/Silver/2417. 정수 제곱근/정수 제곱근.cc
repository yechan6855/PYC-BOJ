#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
    io;
    ll n;
    cin >> n;
    
    ll k = static_cast<ll>(sqrt(n));
    
    if (k * k < n) {
        k++;
    }
    
    cout << k << endl;
    return 0;
}