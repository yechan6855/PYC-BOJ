#include <bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
using namespace std;

vector<int> com(const vector<char>& pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    int k = 0;
    for (int q = 1; q < m; q++) {
        while (k > 0 && pattern[k] != pattern[q])
            k = pi[k - 1];
        if (pattern[k] == pattern[q])
            k++;
        pi[q] = k;
    }
    return pi;
}

int kmp(const vector<char>& text, const vector<char>& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> pi = com(pattern);
    int q = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i])
            q = pi[q - 1];
        if (pattern[q] == text[i])
            q++;
        if (q == m) {
            cnt++;
            q = pi[q - 1];
        }
    }
    return cnt;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int32_t main() {
    io;
    int N;
    cin >> N;

    vector<char> tar(N);
    vector<char> rul(N);

    for (int i = 0; i < N; i++) {
        cin >> tar[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> rul[i];
    }

    if (N == 1) {
        if (tar[0] == rul[0]) {
            cout << "1/1" << endl;
        } else {
            cout << "0/1" << endl;
        }
        return 0;
    }

    vector<char> ext = rul;
    ext.insert(ext.end(), rul.begin(), rul.end() - 1);

    int mat = kmp(ext, tar);
    int tot = N;

    int divisor = gcd(mat, tot);

    cout << mat / divisor << "/" << tot / divisor << endl;

    return 0;
}