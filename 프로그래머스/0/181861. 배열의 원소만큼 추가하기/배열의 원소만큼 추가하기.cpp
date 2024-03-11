#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for(int i=0; i<arr.size(); i++){
        for(int j=1; j<=arr[i]; j++){
            answer.push_back(arr[i]);
        }
    }
    return answer;
}