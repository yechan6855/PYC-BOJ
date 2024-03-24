#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}

int solution(vector<int> array) {
    int answer = 0;
    
    for(int i=0; i<array.size(); i++) mp[array[i]]++;
    
    vector<pair<int, int>> v(mp.begin(), mp.end());
    
    sort(v.begin(), v.end(), compare);
    
    if(v[0].second==v[1].second) answer=-1;
    else answer=v[0].first;
    
    return answer;
}