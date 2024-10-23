#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, L;
    cin >> N >> L;

    for(ll len = L; len <= 100; len++) {
        ll sum = (len - 1) * len / 2;
        ll start = (N - sum) / len;

        if(start < 0) break;

        if((N - sum) % len == 0) {
            bool valid = true;

            if(start < 0) {
                valid = false;
            } else {
                ll total = 0;
                for(ll i = 0; i < len; i++) {
                    total += (start + i);
                }
                if(total != N) valid = false;
            }

            if(valid) {
                for(ll i = 0; i < len; i++) {
                    cout << start + i << " ";
                }
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}