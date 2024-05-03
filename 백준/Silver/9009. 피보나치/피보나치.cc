#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int MaxFibo(int n) {
    int f0 = 0, f1 = 1, f2;
    if (n <= 1)
        return n;
    while (1) {
        f2 = f1 + f0;
        if (f2 == n)
            return f2;
        else if (f2 > n)
            return f1;
        f0 = f1;
        f1 = f2;
    }
}

void fibo(int n) {
    int max;
    if (n == 1) {
        cout<<"1";
        return;
    }
    max = MaxFibo(n);
    if ((n - max) > 0) {
        fibo(n - max);
        cout<<" ";
    }
    cout<<max;
}
int main() {
    int t;
    int n;
    cin>>t;
    while (t--) {
        cin>>n;
        fibo(n);
        cout<<endl;
    }
}