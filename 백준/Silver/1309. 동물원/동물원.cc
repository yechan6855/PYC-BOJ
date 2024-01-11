#include <iostream>
using namespace std;
#define MAX 100000
#define MOD 9901

int main()
{
    int dp[MAX+1][3];
    int n;
    cin>>n;

    dp[1][0]=dp[1][1]=dp[1][2]=1;
    for(int i=2; i<=n; i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%MOD;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%MOD;
        dp[i][2]=(dp[i-1][0]+dp[i-1][1])%MOD;
    }
    cout<<(dp[n][0]+dp[n][1]+dp[n][2])%MOD<<"\n";
}