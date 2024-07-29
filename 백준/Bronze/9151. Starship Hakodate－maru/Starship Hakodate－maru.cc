#include <bits/stdc++.h>
#define endl "\n"
#define vi vector<int>
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

vi pc(int l){
    vi c;
    for(int n=0; n*n*n<=l; ++n){
        c.pb(n*n*n);
    }
    return c;
}
vi pt(int l){
    vi t;
    for(int n=0; ; ++n){
        int x=n*(n+1)*(n+2)/6;
        if(x>l) break;
        t.pb(x);
    }
    return t;
}

set<int> ps(const vi& c, const vi& t){
    set<int>s;
    for(int a:c){
        for(int b:t){
            int x=a+b;
            if(x>151200)break;
            s.insert(x);
        }
    }
    return s;
}

int main(){
    io;
    vi c=pc(151200);
    vi t=pt(151200);
    set<int>s=ps(c,t);
    vi v(s.begin(),s.end());

    int x;
    while(cin>>x&&x!=0){
        auto it= upper_bound(v.begin(),v.end(),x);
        --it;
        cout<<*it<<endl;
    }
}