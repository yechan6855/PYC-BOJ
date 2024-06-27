#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

bool is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void pwd(vector<char>& s, vector<char>& pswd, int L, int index, int vowel_count, int consonant_count) {
    if (pswd.size() == L) {
        if (vowel_count >= 1 && consonant_count >= 2) {
            for (char c : pswd) {
                cout << c;
            }
            cout << endl;
        }
        return;
    }

    for (int i = index; i < s.size(); ++i) {
        pswd.pb(s[i]);
        if (is_vowel(s[i])) {
            pwd(s, pswd, L, i + 1, vowel_count + 1, consonant_count);
        } else {
            pwd(s, pswd, L, i + 1, vowel_count, consonant_count + 1);
        }
        pswd.pop_back();
    }
}

int32_t main() {
    io;
    int L, C;
    cin >> L >> C;

    vector<char> s(C);
    for (int i = 0; i < C; ++i) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    vector<char> paswd;
    pwd(s, paswd, L, 0, 0, 0);

    return 0;
}