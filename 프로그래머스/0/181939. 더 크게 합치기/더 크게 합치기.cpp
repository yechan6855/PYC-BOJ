#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string A=to_string(a)+to_string(b);
    string B=to_string(b)+to_string(a);
    if(stoi(A)>stoi(B)){
        answer=stoi(A);
    }else{
        answer=stoi(B);
    }
    return answer;
}