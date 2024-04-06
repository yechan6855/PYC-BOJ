#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    string number;
    vector<char> vec;

    cin >> N >> K;
    cin >> number;

    vec.reserve(N);

    for (char digit : number) {
        while (!vec.empty() && vec.back() < digit && K > 0) {
            vec.pop_back();
            K--;
        }
        vec.push_back(digit);
    }

    while (K-- > 0 && !vec.empty()) {
        vec.pop_back();
    }

    string result(vec.begin(), vec.end());

    cout << result << '\n';

    return 0;
}