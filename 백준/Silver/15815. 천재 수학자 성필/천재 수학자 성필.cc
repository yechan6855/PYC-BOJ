#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string expr;
    cin >> expr;

    stack<long long> s;

    for(char c : expr){
        if(isdigit(c)){
            s.push(c - '0');
        }
        else{
            if(s.size() < 2){
                return 0;
            }
            long long operand2 = s.top(); s.pop();
            long long operand1 = s.top(); s.pop();
            long long result = 0;

            switch(c){
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    return 0;
            }
            s.push(result);
        }
    }

    if(!s.empty()){
        cout << s.top();
    }

    return 0;
}