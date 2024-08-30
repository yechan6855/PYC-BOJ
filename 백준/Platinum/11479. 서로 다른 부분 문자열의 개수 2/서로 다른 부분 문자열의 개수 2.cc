#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

int t;
int SA[MAX], lcp[MAX], g[MAX], tg[MAX];
int r[MAX], LCP[MAX];

bool cmp(int x, int y) {
    if (g[x] == g[y])
        return g[x + t] < g[y + t];
    return g[x] < g[y];
}

void getSA(const string& s) {
    t = 1;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        SA[i] = i;
        g[i] = s[i] - 'a';
    }

    while (t <= n) {
        g[n] = -1;
        sort(SA, SA + n, cmp);
        tg[SA[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (cmp(SA[i - 1], SA[i]))
                tg[SA[i]] = tg[SA[i - 1]] + 1;
            else
                tg[SA[i]] = tg[SA[i - 1]];
        }

        for (int i = 0; i < n; i++)
            g[i] = tg[i];

        t *= 2;
    }
}

void getLCP(const string& s) {
    int n = s.size();
    for (int i = 0; i < n; i++)
        r[SA[i]] = i;

    int len = 0;
    for (int i = 0; i < n; i++) {
        int k = r[i];
        if (k) {
            int j = SA[k - 1];
            while (s[j + len] == s[i + len])
                len++;
            lcp[k] = len;
            if (len)
                len--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    getSA(s);
    getLCP(s);

    long long result = (long long)n * (n + 1) / 2;
    for (int i = 1; i < n; i++)
        result -= lcp[i];

    cout << result << '\n';

    return 0;
}