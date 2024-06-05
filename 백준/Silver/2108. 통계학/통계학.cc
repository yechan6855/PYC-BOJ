#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int,int>
#define mi map<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void build(vi& segTree, const vi& arr, int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(segTree, arr, 2 * node + 1, start, mid);
        build(segTree, arr, 2 * node + 2, mid + 1, end);
        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }
}

int querySum(vi& segTree, int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
        return 0;
    }
    if (L <= start && end <= R) {
        return segTree[node];
    }
    int mid = (start + end) / 2;
    int l = querySum(segTree, 2 * node + 1, start, mid, L, R);
    int r = querySum(segTree, 2 * node + 2, mid + 1, end, L, R);
    return l + r;
}

int32_t main() {
    io;
    int N;
    cin >> N;
    vi arr(N);
    mi frequency;
    int sum = 0;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        sum += arr[i];
        frequency[arr[i]]++;
    }

    double mean = round((double)sum / N);
    if (mean == -0) {
        mean = 0;
    }
    cout << mean << endl;

    sort(arr.begin(), arr.end());
    int median = arr[N / 2];
    cout << median << endl;

    int mode = arr[0];
    int maxFreq = 0;
    bool second = false;
    for (auto& [num, freq] : frequency) {
        if (freq > maxFreq) {
            maxFreq = freq;
            mode = num;
            second = false;
        } else if (freq == maxFreq && !second) {
            mode = num;
            second = true;
        }
    }
    cout << mode << endl;

    int range = arr.back() - arr.front();
    cout << range << endl;
    return 0;
}