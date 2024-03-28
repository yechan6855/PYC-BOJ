#include <bits/stdc++.h>

using namespace std;

void makeSums(int start, int end, vector<long long>& arr, vector<long long>& vec, long long sum){
    if(start>end){
        vec.push_back(sum);
    }
    else{
        makeSums(start+1, end, arr, vec, sum);
        makeSums(start+1, end, arr, vec, sum + arr[start]);
    }
}

int main() {
    int N, C;
    cin >> N >> C;

    vector<long long> arr;
    arr.resize(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<long long> lSums, rSums;
    makeSums(0, N / 2 - 1, arr, lSums, 0);
    makeSums(N / 2, N - 1, arr, rSums, 0);

    sort(rSums.begin(), rSums.end());

    int lSumsSize = lSums.size(), ans = 0;
    for (int i = 0; i < lSumsSize; i++) {
        long long restC = C - lSums[i];
        ans += upper_bound(rSums.begin(), rSums.end(), restC) - rSums.begin();
    }
    cout << ans;

    return 0;
}