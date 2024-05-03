#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
using namespace std;
int N, L, T, X, d[100005];
pi a[100005];

bool f[100005];

int32_t main()
{
    cin>> N >> L >> T ;
    for(int i=1;i<=N;i++) {
        char T[2]; a[i].second = i;
        cin>>a[i].first>>T;
        if(T[0] == 'L' || T[0] == 'l') f[i] = true;
    }
    cin>>X;
    sort(a+1, a+1+N);
    for(int i=1;i<=N;i++) {
        d[i] = a[i].second;
        a[i].second = (d[i] == X);
        if(f[d[i]]) a[i].first -= T;
        else a[i].first += T;
        a[i].first = (a[i].first % (2*L) + 2*L) % (2*L);
        if(a[i].first >= L) a[i].first = 2*L - a[i].first;
    }
    sort(a+1, a+1+N);
    for(int i=1;i<=N;i++) {
        if(a[i].second) {
            cout<<d[i];
            return 0;
        }
    }
}