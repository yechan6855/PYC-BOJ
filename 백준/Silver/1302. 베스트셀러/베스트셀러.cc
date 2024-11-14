#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string book;
    map<string, int> books;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> book;
        books[book]++;
    }

    int cnt = 0;
    string ans;

    for (auto it = books.begin(); it != books.end(); it++) {
        if (it->second > cnt) {
            cnt = it->second;
            ans = it->first;
        } else if (it->second == cnt && it->first < ans) {
            ans = it->first;
        }
    }

    cout << ans << '\n';

    return 0;
}