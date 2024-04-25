#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> solve(const string& pattern) {
    int m = pattern.length();
    vector<int> fail(m, 0);
    int i = 1, j = 0;

    while (i < m) {
        if (pattern[i] == pattern[j]) {
            fail[i++] = ++j;
        } else if (j > 0) {
            j = fail[j - 1];
        } else {
            fail[i++] = 0;
        }
    }

    return fail;
}

vector<int> kmpSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> fail = solve(pattern);
    vector<int> occurrences;
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) {
                occurrences.push_back(i - m);
                j = fail[j - 1];
            }
        } else if (j > 0) {
            j = fail[j - 1];
        } else {
            i++;
        }
    }

    return occurrences;
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    vector<int> occurrences = kmpSearch(text, pattern);

    cout << occurrences.size() << endl;
    for (int i = 0; i < occurrences.size(); i++) {
        cout << occurrences[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}