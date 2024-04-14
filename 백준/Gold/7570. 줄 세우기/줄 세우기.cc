#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> position(N + 1);
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        position[num] = i;
    }
    int maxLen = 0;
    int curLen = 1;
    for (int i = 2; i <= N; i++) {
        if (position[i] > position[i - 1]) {
            curLen++;
        } else {
            maxLen = max(maxLen, curLen);
            curLen = 1;
        }
    }
    maxLen = max(maxLen, curLen);
    cout << N - maxLen << endl;
    return 0;
}