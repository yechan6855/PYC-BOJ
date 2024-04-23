#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int n=x;
    int a=0;
    while(n!=0){
        a+=n%10;
        n/=10;
    }
    return x%a==0?true:false;
}