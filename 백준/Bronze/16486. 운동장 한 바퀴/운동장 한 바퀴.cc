#include <iostream>
using namespace std;
const double PI = 3.141592;
int main(void)
{
    ios_base::sync_with_stdio(0);
   
    cin.tie(0);
    double d1, d2;
    cin >> d1 >> d2;
    double result = 2 * d1 + 2 * d2 * PI;
    printf("%.7lf\n", result);
    return 0;
}