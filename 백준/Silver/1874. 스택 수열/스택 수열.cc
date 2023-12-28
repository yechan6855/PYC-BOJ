#include <iostream>
#include <stack>
using namespace std;



int main() {
	int N, nownum = 1, input;
	stack<int> stk;
	string ans = "+";
	stk.push(nownum++);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		while (stk.empty() || stk.top() < input) {
			ans += "+";
			stk.push(nownum++);
		}
		if (stk.top() == input) {
			ans += "-";
			stk.pop();
		}
		else {
			ans = "NO";
			cout << ans << endl;
			return 0;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}