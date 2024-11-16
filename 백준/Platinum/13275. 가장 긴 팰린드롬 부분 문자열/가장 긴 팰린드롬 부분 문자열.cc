#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string t = "#";
    for(char c : s){
        t += c;
        t += '#';
    }
    int n = t.length();
    vector<int> p(n, 0);
    int c = 0, r = 0;

    for(int i=0; i<n; ++i){
        int mirr = 2*c - i;

        if(i < r){
            p[i] = min(r - i, p[mirr]);
        }

        int a = i + p[i] + 1;
        int b = i - p[i] - 1;

        while(a < n && b >=0 && t[a] == t[b]){
            p[i]++;
            a++;
            b--;
        }

        if(i + p[i] > r){
            c = i;
            r = i + p[i];
        }
    }

    int ans = 0;

    for(int len : p){
        if(len > ans){
            ans = len;
        }
    }
    cout << ans;
}