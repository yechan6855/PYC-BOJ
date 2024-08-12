#include <bits/stdc++.h>
using namespace std;

vector<long long> n;

void generate(long long num, int last_digit) {
    n.push_back(num);

    for (int i = 0; i < last_digit; i++) {
        generate(num * 10 + i, i);
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i <= 9; i++) {
        generate(i, i);
    }

    sort(n.begin(), n.end());

    if (N >= n.size()) {
        cout << -1 << endl;
    } else {
        cout << n[N] << endl;
    }

    return 0;
}