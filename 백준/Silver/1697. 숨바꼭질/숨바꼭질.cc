#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define di deque<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    if(n>=k){
        cout<<n-k<<endl;
        return 0;
    }

    vi visited(100001,-1);
    qi q;
    q.push(n);
    visited[n]=0;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        int next[]={cur-1,cur+1,cur*2};
        for(int nxt:next){
            if(nxt>=0&&nxt<=100000&& visited[nxt]==-1){
                visited[nxt]=visited[cur]+1;
                q.push(nxt);

                if(nxt==k){
                    cout<<visited[nxt]<<endl;
                    return 0;
                }
            }
        }
    }
}