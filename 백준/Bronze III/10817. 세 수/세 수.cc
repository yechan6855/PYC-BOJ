//세 정수 A, B, C가 주어진다. 이때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오.

#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a>=b && a>=c)
    {
        if(b>=c)
        {
            cout << b;
        }
        else
        {
            cout << c;
        }
    }
    else if(b>=a && b>=c)
    {
        if(a>=c)
        {
            cout << a;
        }
        else
        {
            cout << c;
        }
    }
    else
    {
        if(a>=b)
        {
            cout << a;
        }
        else
        {
            cout << b;
        }
    }
    return 0;
}