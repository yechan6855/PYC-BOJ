#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int arr[26] = {0,};
    for(int i = 0; i < s.length(); i++){
        arr[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        cout << arr[i] << " ";
    }
    return 0;
}