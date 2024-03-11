#include <iostream>
#include <string>
#include <cctype>


using namespace std;

int main() {
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        string a="";
        for(int i=0; i<s.size(); i++){
             a+=tolower(s[i]);

        }
        cout<<a<<endl;
    }
}

// n^4 가능