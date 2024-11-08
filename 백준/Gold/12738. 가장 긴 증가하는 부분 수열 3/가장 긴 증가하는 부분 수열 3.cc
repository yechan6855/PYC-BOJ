#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> arr(n);
    vector<long long> LIS;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    LIS.push_back(arr[0]);

    for(int i = 1; i < n; i++) {
        if(LIS.back() < arr[i]) {
            LIS.push_back(arr[i]);
        }
        else {
            int pos = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
            LIS[pos] = arr[i];
        }
    }

    cout << LIS.size() << '\n';

    return 0;
}