#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define fi first
#define se second
using namespace std;

class SegmentTree{
private:
    vector<int>tree;
    vector<bool>lazy;
    int n;

    void updateRange(int node, int start, int end, int left, int right){
        if(lazy[node]){
            tree[node]=(end-start+1)-tree[node];
            if(start!=end){
                lazy[node*2]=!lazy[node*2];
                lazy[node*2+1]=!lazy[node*2+1];
            }
            lazy[node]=false;
        }

        if(start>right||end<left){
            return;
        }

        if(start>=left&&end<=right){
            tree[node]=(end-start+1)-tree[node];
            if(start!=end){
                lazy[node*2]=!lazy[node*2];
                lazy[node*2+1]=!lazy[node*2+1];
            }
            return;
        }

        int mid=(start+end)/2;
        updateRange(node*2,start,mid,left,right);
        updateRange(node*2+1,mid+1,end,left,right);
        tree[node]=tree[node*2]+tree[node*2+1];
    }

    int query(int node, int start, int end, int left, int right){
        if(start>right||end<left){
            return 0;
        }
        if(lazy[node]){
            tree[node]=(end-start+1)-tree[node];
            if(start!=end){
                lazy[node*2]=!lazy[node*2];
                lazy[node*2+1]=!lazy[node*2+1];
            }
            lazy[node]=false;
        }
        if(start>=left&&end<=right){
            return tree[node];
        }

        int mid=(start+end)/2;
        int left_query = query(node*2,start,mid,left,right);
        int right_query = query(node*2+1,mid+1,end,left,right);
        return left_query+right_query;
    }

public:
    SegmentTree(int size){
        n=size;
        tree.resize(4*n,0);
        lazy.resize(4*n,false);
    }

    void updateRange(int left, int right){
        updateRange(1,0,n-1,left,right);
    }
    int query(int left, int right){
        return query(1,0,n-1,left,right);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    SegmentTree st(n);

    for(int i=0; i<m; ++i){
        int o,s,t;
        cin>>o>>s>>t;
        if(o==0){
            st.updateRange(s-1,t-1);
        }else{
            cout<<st.query(s-1,t-1)<<endl;
        }
    }
    return 0;
}