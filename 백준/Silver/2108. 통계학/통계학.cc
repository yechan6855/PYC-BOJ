#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	double element;
	vector <double> v;
	double mean = 0;
	double median = 0;
	double mode = 0;
	double range = 0;

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> element;
		v.push_back(element);
	}
	for (int i = 0; i < N; i++) {
		mean += v[i];
	}
	mean = round(mean / N);
	// -0 출력 방지
	if (mean == -0) {
		mean = 0;
	}
	sort(v.begin(), v.end());
	if (N == 1) {
		median = v[0];
	}
	else {
		median = v[(N - 1) / 2];
	}
	int count[8001] = { 0, };
	for (int i = 0; i < N; i++) {
		if (v[i] >= 0) {
			count[int(v[i])]++;
		}
		else {
			count[int(fabs(v[i])) + 4000]++;
		}
	}
	int max = count[0];
	int index = 0;
	for (int i = 0; i < 8001; i++) {
		if (max < count[i]) {
			index = i;
			max = count[i];
		}
	}
	vector <double> mv;
	for (int i = 0; i < 8001; i++) {
		if (max == count[i]) {
			if (i <= 4000) {
				mv.push_back(i);
			}
			else {
				mv.push_back((i - 4000) * (-1));
			}
		}
	}
	sort(mv.begin(), mv.end());
	if (mv.size() == 1) {
		mode = mv[0];
	}
	else {
		mode = mv[1];
	}
	range = v[N - 1] - v[0];
	cout << mean << "\n";
	cout << median << "\n";
	cout << mode << "\n";
	cout << range << "\n";

	return 0;
}