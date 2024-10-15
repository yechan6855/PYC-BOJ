#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> intensity(N);
    for(int &x : intensity) cin >> x;

    int window_size = 2*M -1;

    deque<int> dq;

    for(int i=0; i < window_size; ++i){
        while(!dq.empty() && intensity[i] >= intensity[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << intensity[dq.front()];

    for(int i = window_size; i < N; ++i){
        while(!dq.empty() && dq.front() <= i - window_size){
            dq.pop_front();
        }

        while(!dq.empty() && intensity[i] >= intensity[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);

        cout << " " << intensity[dq.front()];
    }
    cout << "\n";
}