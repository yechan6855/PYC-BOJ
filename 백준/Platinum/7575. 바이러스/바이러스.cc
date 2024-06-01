#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> LPS(const vector<int>& pat) {
    int M = pat.size();
    vector<int> lps(M);
    int len = 0;
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool KMP(const vector<int>& pat, const vector<int>& txt) {
    int M = pat.size();
    int N = txt.size();
    vector<int> lps = LPS(pat);

    int i = 0;
    int j = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            return true;
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
}

bool Virus(const vector<vector<int>>& progs, int K) {
    int N = progs.size();

    for (int i = 0; i + K <= progs[0].size(); i++) {
        vector<int> cand(progs[0].begin() + i, progs[0].begin() + i + K);
        vector<int> rev_cand = cand;
        reverse(rev_cand.begin(), rev_cand.end());

        bool isCommon = true;
        for (int j = 1; j < N; j++) {
            if (!KMP(cand, progs[j]) && !KMP(rev_cand, progs[j])) {
                isCommon = false;
                break;
            }
        }

        if (isCommon) {
            return true;
        }
    }

    return false;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> progs(N);

    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        progs[i].resize(M);
        for (int j = 0; j < M; j++) {
            cin >> progs[i][j];
        }
    }

    if (Virus(progs, K)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}