#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    int s = 0;
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        int res;
        cin >> res;

        if(res == 1) {
            cnt++;
            s += cnt;
        }
        else {
            cnt = 0;
        }
    }

    cout << s << "\n";

    return 0;
}