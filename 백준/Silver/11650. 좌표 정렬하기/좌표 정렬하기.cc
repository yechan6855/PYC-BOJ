#include <iostream>
#include <algorithm>
using namespace std;

class coordinate {
public:
	int x;
	int y;
};
bool cmp(coordinate a, coordinate b) {
	if (a.x == b.x) {         
		return a.y < b.y;
	}
	else {
		return a.x < b.x;
	}
}
coordinate* c = new coordinate[100000];
int main() {
	int N;
	int numx, numy;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c[i].x >> c[i].y;
	}
	stable_sort(c, c + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << c[i].x << " " << c[i].y << "\n";
	}
	return 0;
}