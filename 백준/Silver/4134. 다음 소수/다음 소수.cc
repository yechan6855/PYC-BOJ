#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
//-----------------------------------------------------------
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; ++i) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}
//-----------------------------------------------------------
int32_t main()
{
    int t,n;
    cin >> t;

    for(int i=0; i<t; ++i){
        cin>>n;
        while(!is_prime(n)){
            n++;
        }
        cout<<n<<endl;
    }
    return 0;
}
//-----------------------------------------------------------