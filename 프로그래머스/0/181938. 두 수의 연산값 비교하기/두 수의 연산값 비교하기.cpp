#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string answerA;
    int answerB;
    answerA=to_string(a)+to_string(b);
    answerB=2*a*b;
    if(stoi(answerA)>answerB){
        return stoi(answerA);
    }else{
        return answerB;
    }
}