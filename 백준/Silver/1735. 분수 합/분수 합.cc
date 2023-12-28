#include <iostream>
using namespace std;
int gcd(int x, int y){
    int z = 1;
    while(y != 0){
        z = x % y;
        x = y;
        y = z;
    }
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    int e, f;
    cin >> a >> b >> c >> d;
    e = a * d + c * b;
    f = b * d;
    int min = gcd(e, f);
    e /= min;
    f /= min;
    cout << e << ' ' << f << '\n';;
    return 0;
}