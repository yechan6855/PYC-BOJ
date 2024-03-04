#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        long long ans = 1;
        for(int i = 1; i <= N; i++){
            ans *= M - i + 1;
            ans /= i;
        }
        cout << ans << '\n';
    }
    return 0;
}