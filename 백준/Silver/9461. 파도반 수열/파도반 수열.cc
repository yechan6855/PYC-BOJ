#include <iostream>
#define ll unsigned long long
using namespace std;

ll arr[101]={0,1,1,};
ll p(int N){
    if(N<3){
        return arr[N];
    }else if(arr[N]==0){
        arr[N]=p(N-2)+p(N-3);
    }
    return arr[N];
}
int main()
{
    ll T;
    int N;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N;
        cout<<p(N)<<"\n";
    }
}