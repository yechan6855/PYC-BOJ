#include <bits/stdc++.h>
#define ull unsigned long long
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
    io;
    ull n;
    cin >> n;
    if(n==0){
        cout<<0;
        return 0;
    }
    ull l = 0;
    ull r = sqrt(n) + 1;
    ull ans = r;

    while (l <= r) {
        ull mid = (l + r) / 2;
        ull square = mid * mid;

        if (square >= n) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}