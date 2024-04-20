#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    cin >> x;

    sort(seq.begin(), seq.end());

    int left = 0, right = n - 1;
    int count = 0;

    while (left < right) {
        int sum = seq[left] + seq[right];
        if (sum == x) {
            count++;
            left++;
            right--;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    cout << count << endl;
    return 0;
}