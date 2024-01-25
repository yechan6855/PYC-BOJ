#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long N; cin >> N;
	cout << (N * (N - 1) * (N - 2)) / 6 << '\n' << 3;
}