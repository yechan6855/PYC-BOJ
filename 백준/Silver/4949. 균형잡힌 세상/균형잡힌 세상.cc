#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define endl "\n"
using namespace std;

bool isBalance(const string& str){
    stack<char>s;
    for(char ch:str){
        if(ch=='(' || ch=='['){
            s.push(ch);
        }else if(ch==')'){
            if(s.empty() || s.top() != '('){
                return false;
            }
            s.pop();
        }else if(ch==']'){
            if(s.empty() || s.top() != '['){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int32_t main() {
    string s;
    while(true){
        getline(cin,s);
        if(s=="."){
            break;
        }
        if(isBalance(s)){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
}