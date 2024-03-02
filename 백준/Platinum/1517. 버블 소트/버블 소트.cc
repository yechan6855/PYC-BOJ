//boj 1517

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[500001];
int temp[500001];
long long ans = 0;

void merge(int start, int end) {
    if (start == end) return;
    int mid = (start + end) / 2;
    merge(start, mid);
    merge(mid + 1, end);
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            ans += (mid - i + 1);
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }
    for (int i = start; i <= end; i++) {
        arr[i] = temp[i - start];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    merge(0, n - 1);
    cout << ans;
    return 0;
}