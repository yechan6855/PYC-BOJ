#include <bits/stdc++.h>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main(){
    io;
    int d,h,m;
    cin>>d>>h>>m;
    d*=1440;
    h*=60;
    int time=d+h+m;
    int time2=11*1440+11*60+11;
    if(time2>time){
        cout<<-1;
        return 0;
    }
    cout<<time-time2;
}