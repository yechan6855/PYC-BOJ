#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 3; // '^' 연산자 (우선순위가 가장 높음)
}

string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> s;

    for (char ch : infix) {
        if (isalpha(ch)) {
            postfix += ch; // 피연산자는 그대로 출력
        } else if (ch == '(') {
            s.push(ch); // 여는 괄호는 스택에 push
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // 여는 괄호는 pop하여 무시
        } else { // 연산자인 경우
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << postfix << endl;

    return 0;
}