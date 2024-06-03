#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

vector<int> Suffix(const string &s) {
    int n = s.size();
    vector<int> Array(n), classes(n);
    for (int i = 0; i < n; i++) {
        Array[i] = n - 1 - i;
        classes[i] = s[i];
    }
    stable_sort(Array.begin(), Array.end(), [&](int l, int r) { return s[l] < s[r]; });

    for (int len = 1; len < n; len <<= 1) {
        vector<int> c(classes);
        for (int i = 0; i < n; i++) {
            bool same = i && Array[i - 1] + len < n
                        && c[Array[i]] == c[Array[i - 1]]
                        && c[Array[i] + len / 2] == c[Array[i - 1] + len / 2];
            classes[Array[i]] = same ? classes[Array[i - 1]] : i;
        }
        vector<int> cnt(n), s(Array);
        for (int i = 0; i < n; i++) cnt[i] = i;
        for (int i = 0; i < n; i++) {
            int s1 = s[i] - len;
            if (s1 >= 0) Array[cnt[classes[s1]]++] = s1;
        }
    }
    return Array;
}

vector<int> LCP(const string &s, const vector<int> &Array) {
    int n = s.size();
    vector<int> rank(n), lcp(n);
    for (int i = 0; i < n; i++) rank[Array[i]] = i;
    for (int i = 0, h = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = Array[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }
    return lcp;
}

int main() {
    io;
    int L;
    string s;
    cin >> L >> s;

    vector<int> Array = Suffix(s);

    vector<int> lcp = LCP(s, Array);

    int maxLCP = 0;
    for (int i = 1; i < L; i++) {
        if (lcp[i] > maxLCP) {
            maxLCP = lcp[i];
        }
    }

    cout << maxLCP << endl;
    return 0;
}