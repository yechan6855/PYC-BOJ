#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>a;
    int n[7];
    int cnt=0;
    for(int i=0; i<7; i++){
        cin>>n[i];
        if(n[i]%2==1){
            a.push_back(n[i]);
            cnt+=n[i];
        }
    }
    sort(a.begin(),a.end());
    if(cnt==0){
        cout<<-1<<endl;
    }else {
        cout << cnt << "\n" << a.front() << endl;
    }
}