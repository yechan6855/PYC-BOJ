#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.length();
    int cnt = 0;

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[str.length() - 1 - i]) {
            cout << "0" << "\n";
            return 0;
        }
    }
    cout << "1" << "\n";
}