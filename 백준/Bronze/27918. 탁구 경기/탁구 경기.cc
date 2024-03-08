#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    int d_cnt=0;
    int p_cnt=0;
    cin>>N;
    string s[N];
    for(int i=0; i<N; i++){
        cin>>s[i];
        if(s[i]=="D"){
            d_cnt++;
        }else{
            p_cnt++;
        }
        if(d_cnt+2==p_cnt || d_cnt==p_cnt+2){
            break;
        }
    }
    cout<<d_cnt<<":"<<p_cnt<<endl;
}