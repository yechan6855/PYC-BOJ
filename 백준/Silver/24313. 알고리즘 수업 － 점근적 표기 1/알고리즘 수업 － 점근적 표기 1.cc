#include <iostream>
int main() {
    int a1, a0, c, n0;
    std::cin >> a1 >> a0 >> c >> n0;
    std::cout<<((a1*n0+a0<=c*n0)&&(c-a1>=0));
    return 0;
}