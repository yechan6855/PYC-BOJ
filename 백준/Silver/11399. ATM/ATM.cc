#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> P;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	P.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> P[i];
	sort(begin(P), end(P));
	int ret = 0;
	int sum = 0;
	for (int i = 1; i < P.size(); ++i) {
		sum += P[i];
		ret += sum;
	}
	cout << ret;
	return 0;
}