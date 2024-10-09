#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> targets(M);
    for(int &x : targets) cin >> x;

    deque<int> dq;
    for(int i=1; i<=N; ++i) dq.push_back(i);

    int total_operations = 0;

    for(int target : targets){
        int idx=0;
        while(idx < dq.size() && dq[idx] != target) idx++;

        if(idx == dq.size()){
            continue;
        }

        int left_rot = idx;
        int right_rot = dq.size() - idx;

        if(left_rot <= right_rot){
            for(int i=0; i<left_rot; ++i){
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
                total_operations++;
            }
        }
        else{
            for(int i=0; i<right_rot; ++i){
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
                total_operations++;
            }
        }
        dq.pop_front();
    }

    cout << total_operations;
}