#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unsigned long long a;
    unsigned long long b;
    cin>>a>>b;
    cout<<(unsigned long long)(a * b) / gcd(a, b)<<"\n";
}