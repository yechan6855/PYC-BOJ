#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    set<string> s;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if (s.find(str) != s.end()) {
            cnt++;
        }
    }
    cout << cnt;
}