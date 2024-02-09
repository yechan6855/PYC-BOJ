#include <iostream>  
#include <stack>  
#include <string>  
  
using namespace std;  
  
int main() {  
    string input;  
    cin >> input;  
  
    stack<char> s;  
    int result = 0;  
    int temp = 1; 
  
    for (int i = 0; i < input.length(); i++) {  
        char current = input[i];  
  
        if (current == '(') {  
            temp *= 2;  
            s.push('(');  
        } else if (current == '[') {  
            temp *= 3;  
            s.push('[');  
        } else if (current == ')') {  
            if (s.empty() || s.top() != '(') {  
                cout << "0\n";  
                return 0;  
            }  
  
            if (input[i - 1] == '(') {  
                result += temp;  
            }  
  
            temp /= 2;  
            s.pop();  
        } else if (current == ']') {  
            if (s.empty() || s.top() != '[') {  
                cout << "0\n";  
                return 0;  
            }  
  
            if (input[i - 1] == '[') {  
                result += temp;  
            }  
  
            temp /= 3;  
            s.pop();  
        }  
    }  
  
    if (!s.empty()) {  
        cout << "0\n";  
    } else {  
        cout << result << "\n";  
    }  
  
    return 0;  
}