#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);

	map<int, int> m;
	int N, M, n;
	cin >> N;

	while (N--)
	{
		cin >> n;
		m[n]++;
	}

	cin >> M;
	while (M--)
	{
		cin >> n;
		auto it = m.find(n);

		if (it != m.end())
			cout << it->second << ' ';
		else
			cout << "0" << ' ';
	}
}