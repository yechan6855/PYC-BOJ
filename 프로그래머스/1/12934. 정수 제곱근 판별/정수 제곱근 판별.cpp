#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    if(sqrt(n)==int(sqrt(n))){
        answer=(sqrt(n)+1)*(sqrt(n)+1);
    }else{
        answer=-1;
    }
    return answer;
}