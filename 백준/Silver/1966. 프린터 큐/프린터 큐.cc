#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        queue<pair<int,int>>q;
        priority_queue<int>pq;

        for(int i=0; i<n; ++i){
            int priority;
            cin>>priority;
            q.push({priority,i});
            pq.push(priority);
        }

        int cnt=0;
        while(!q.empty()){
            int cur_priority=q.front().fi;
            int cur_index=q.front().se;
            q.pop();

            if(cur_priority==pq.top()){
                pq.pop();
                cnt++;
                if(cur_index==m) {
                    cout << cnt << endl;
                    break;
                }
            }else{
                q.push({cur_priority,cur_index});
            }
        }
    }
}