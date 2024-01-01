#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int N;
    cin>>N;
    
    vector<int> dp(N+1,0);
    
    for(int i=1;i<=N;i++){
        
        dp[i]=i;
        for(int j=1;j*j<=i;j++)
            dp[i]=min(dp[i],dp[i-j*j]+1);
    }
    cout<<dp[N]<<"\n";
}