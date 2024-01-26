#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l[10005];
int r[10005];
int x[10005];
int p[10005];
int n;
int root;

int dfs(int cur, int lim, int& cnt){
    int lv = 0;
    if(l[cur] != -1) lv = dfs(l[cur], lim, cnt);
    int rv = 0;
    if(r[cur] != -1) rv = dfs(r[cur], lim, cnt);
    
    if(x[cur] + lv + rv <= lim)
        return x[cur] + lv + rv;
    
    if(x[cur] + min(lv, rv) <= lim){
        cnt++;
        return x[cur] + min(lv, rv);
    }

    cnt += 2;
    return x[cur];
}

int solve(int lim){
    int cnt = 0;
    dfs(root, lim, cnt);
    cnt++;
    return cnt;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    n = num.size();
    fill(p,p+n,-1);
    for(int i = 0; i < n; i++){
        l[i] = links[i][0];
        r[i] = links[i][1];
        x[i] = num[i];
        if(l[i] != -1) p[l[i]] = i;
        if(r[i] != -1) p[r[i]] = i;
    }
    root = min_element(p,p+n) - p;
    int st = *max_element(x,x+n);
    int en = 1e8;
    while(st < en){
        int mid = (st+en)/2;
        if(solve(mid) <= k) en = mid;
        else st = mid+1;
    }
    return st;
}