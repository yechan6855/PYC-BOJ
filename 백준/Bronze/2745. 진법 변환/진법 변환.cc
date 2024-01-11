#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int a;
    int sum=0;
    cin>>s>>a;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9'){
            sum=sum*a+(s[i]-48);
        }
        else
            sum=sum*a+(s[i]-65+10);
    }
    cout<<sum;
    return 0;
}