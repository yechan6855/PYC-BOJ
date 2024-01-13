#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, s;
int arr[51];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> s;
	for (int i = 0; i < n && s > 0; i++) {
		int idx = i, m = arr[i];
		for (int j = i + 1; j < n && j - i <= s; j++) {
			if (arr[j] > m) {
				m = arr[j];
				idx = j;
			}
		}
		if (idx != i) {
			s -= (idx - i);
			for (int j = idx; j > i; j--) {
				arr[j] = arr[j - 1];
			}
			arr[i] = m;
		}		
	}
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}