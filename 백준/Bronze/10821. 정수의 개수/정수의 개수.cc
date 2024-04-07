#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(const string& s){
    int count=0;
    bool in_integer=false;
    for(char c:s){
        if(isdigit(c)) {
            if (!in_integer) {
                in_integer = true;
                count++;
            }
        } else{
                in_integer=false;
            }
        }
        return count;
    }

int main() {
    string s;
    cin>>s;

    cout << solve(s) << endl;

    return 0;
}