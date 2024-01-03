#include <iostream>
#include <queue>

using namespace std;
int P[48] = { 0 };
int S[48] = { 0 };
int parent[48] = { 0 };
int N;

int Find(int x) {
	if (x == parent[x]) return x;
	return x = Find(parent[x]);
}
void Union(int a, int b) {
	int x = Find(a);
	int y = Find(b);
	if (x == y) return;
	else {
		parent[y] = x;
	}
	return;
}
int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int solve() {
	int vis = 0,cnt = 0;
	int group[48] = { 0 };
	for (int i = 0; i < N; i++) {
		int j = Find(i);
		if (!(vis & (1 << j))) {
			vis = vis | (1 << j);
		}
		group[j]+=1;
	}
	int reg = 1;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (group[i]) {
			reg = lcm(reg, group[i]);
		}
	}
	for (int i = 0; i < N; i++) {
		if (P[i] != (i % 3))
			break;
		if (i == N - 1) return 0;
	}
	for (int k = 1; k < reg; k++) {
		flag = true;
		int tmp[48];
		for (int i = 0; i < N; i++) {
			tmp[S[i]] = P[i];
		}
		for (int i = 0; i < N; i++) {
			P[i] = tmp[i];
			if (P[i] != (i % 3))
				flag = false;
		}
		if (flag){
			return k;
        }
	}
	return -1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		cin >> P[i];
	}
	for (int i = 0; i < N; i++) {		
		cin >> S[i];
		Union(i, S[i]);
	}
	cout << solve();
}