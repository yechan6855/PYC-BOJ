#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> computeLPSArray(vector<int>& pattern) {
    int M = pattern.size();
    vector<int> lps(M, 0);
    int len = 0;
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[len]) {
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

bool KMPSearch(vector<int>& pat, vector<int>& txt) {
    int M = pat.size();
    int N = txt.size();

    vector<int> lps = computeLPSArray(pat);

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

bool isSameClock(vector<int>& clock1, vector<int>& clock2) {
    int n = clock1.size();
    
    vector<int> diff1, diff2;
    for (int i = 1; i < n; i++) {
        diff1.push_back((clock1[i] - clock1[i-1] + 360000) % 360000);
        diff2.push_back((clock2[i] - clock2[i-1] + 360000) % 360000);
    }
    diff1.push_back((clock1[0] - clock1[n-1] + 360000) % 360000);
    diff2.push_back((clock2[0] - clock2[n-1] + 360000) % 360000);
    
    vector<int> txt = diff2;
    txt.insert(txt.end(), diff2.begin(), diff2.end());
    
    return KMPSearch(diff1, txt);
}

int main() {
    int n;
    cin >> n;
    vector<int> clock1(n), clock2(n);

    for (int i = 0; i < n; i++) {
        cin >> clock1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> clock2[i];
    }

    sort(clock1.begin(), clock1.end());
    sort(clock2.begin(), clock2.end());

    if (isSameClock(clock1, clock2)) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}