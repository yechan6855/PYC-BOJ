#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a=int(sqrt(double(n)));
    
    for(int i=1; i<=a; i++){
        if(n%i==0){
            answer+=2;
        }
    }if(a*a==n){
        answer--;
    }
    return answer;
}