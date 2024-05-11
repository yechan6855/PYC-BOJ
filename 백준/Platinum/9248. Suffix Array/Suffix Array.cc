#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

vector<int> suffix_array(const string& S) {
    int n = S.length();
    vector<int> sa(n), ranks(n), new_ranks(n);
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        ranks[i] = S[i];
    }

    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int i, int j) {
            if (ranks[i] != ranks[j]) return ranks[i] < ranks[j];
            int ri = i + k < n ? ranks[i + k] : -1;
            int rj = j + k < n ? ranks[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);

        new_ranks[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            new_ranks[sa[i]] = new_ranks[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        }
        ranks.swap(new_ranks);
    }
    return sa;
}

vector<int> lcp_array(const string& S, const vector<int>& sa) {
    int n = S.length();
    vector<int> lcp(n), rank(n);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;

    int h = 0;
    lcp[0] = -1;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = sa[rank[i] - 1];
            while (i + h < n && j + h < n && S[i + h] == S[j + h]) h++;
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }
    return lcp;
}

int32_t main() {
    string S;
    cin >> S;

    vector<int> sa = suffix_array(S);
    vector<int> lcp = lcp_array(S, sa);

    for (int i = 0; i < sa.size(); i++) {
        if (i > 0) cout << " ";
        cout << sa[i] + 1;
    }
    cout << endl;

    for (int i = 0; i < lcp.size(); i++) {
        if (i > 0) cout << " ";
        if (lcp[i] == -1) cout << 'x';
        else cout << lcp[i];
    }
    cout << endl;

    return 0;
}