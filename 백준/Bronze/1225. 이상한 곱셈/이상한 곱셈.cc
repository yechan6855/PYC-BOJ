#include <iostream>
#include <string>
#define ll long long
using namespace std;

ll newMultiplication(const string& A, const string& B) {
    ll result = 0;
    for (char digit_A : A) {
        for (char digit_B : B) {
            result += (digit_A - '0') * (digit_B - '0');
        }
    }
    return result;
}

int main() {
    string A, B;
    cin >> A >> B;

    cout << newMultiplication(A, B) << endl;

    return 0;
}