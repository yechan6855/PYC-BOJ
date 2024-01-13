#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int side_length = pow(2, n) + 1;
    int result = side_length * side_length;
    cout << result << "\n";
}
