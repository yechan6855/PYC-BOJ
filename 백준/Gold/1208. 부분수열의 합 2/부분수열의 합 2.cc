#include <bits/stdc++.h>
using namespace std;

int arr[41];
int N, S;
long long cnt;
vector<int> a, b;

void numbersA(int idx, int sum) {
    sum += arr[idx];
    if (idx >= N / 2) return;
    if (sum == S) cnt++;

    a.push_back(sum);
    numbersA(idx + 1, sum - arr[idx]);
    numbersA(idx + 1, sum);
}

void numbersB(int idx, int sum) {
    sum += arr[idx];
    if (idx >= N) return;
    if (sum == S) cnt++;

    b.push_back(sum);
    numbersB(idx + 1, sum - arr[idx]);
    numbersB(idx + 1, sum);
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];

    numbersA(0, 0);
    numbersB(N / 2, 0);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++) {
        int temp = S - a[i];
        int lower = lower_bound(b.begin(), b.end(), temp) - b.begin();
        int upper = upper_bound(b.begin(), b.end(), temp) - b.begin();
        cnt += upper - lower;
    }

    cout << cnt;

    return 0;
}