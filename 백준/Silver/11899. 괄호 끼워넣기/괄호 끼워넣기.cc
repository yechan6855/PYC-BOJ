#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    stack<char> st;
    int count = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                count++;
            }
        }
    }

    count += st.size();

    cout << count << endl;

    return 0;
}