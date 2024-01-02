#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    string word;
    int ans = 0;
    for (int i = 0; i < n; i++){
        bool isgroup = true;
        cin >> word;
        word.erase(unique(word.begin(), word.end()), word.end());
        sort(word.begin(), word.end());
        for (int k = 0; k < word.length()-1;k++){
            if(word[k] == word[k+1]){
                isgroup = false;
                break;
            }
        }
        if(isgroup){
            ans++;
        }
    }
    cout << ans;
    return 0;
}