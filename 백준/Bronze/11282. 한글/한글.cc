#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    int b = 0xAC00;

    int u = b + n - 1;

    cout << char(0xE0 | (u >> 12));
    cout << char(0x80 | ((u >> 6) & 0x3F));
    cout << char(0x80 | (u & 0x3F));

    return 0;
}