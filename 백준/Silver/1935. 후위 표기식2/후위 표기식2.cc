#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string expression;
    vector<double> values;
    stack<double> st;

    cin >> N >> expression;

    for (int i = 0; i < N; i++) {
        double val;
        cin >> val;
        values.push_back(val);
    }

    for (char c : expression) {
        if (c >= 'A' && c <= 'Z') {
            st.push(values[c - 'A']);
        } else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();

            switch(c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }

    cout << fixed << setprecision(2) << st.top() << endl;

    return 0;
}