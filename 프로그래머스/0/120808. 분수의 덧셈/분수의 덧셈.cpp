#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
   return (a % b == 0 ? b : gcd(b, a % b));
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;

    if(denom1 == denom2)
    {
        int numer = numer1 + numer2;
        int gcd_num;        
        gcd_num = gcd(numer,denom1);


        answer.push_back(numer / gcd_num);
        answer.push_back(denom1 / gcd_num);
    }
    else
    {
        int denom = denom1 * denom2;
        int numer = (numer1 * denom2) + (numer2 * denom1);

        int gcd_num;

        if(numer > denom) gcd_num = gcd(numer,denom);
        else gcd_num = gcd(denom, numer);

        answer.push_back(numer / gcd_num);
        answer.push_back(denom / gcd_num);
    }

    return answer;
}