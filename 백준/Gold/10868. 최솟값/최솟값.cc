#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> arr, minTree;

int minInit(int start, int end, int node) {
    if (start == end) {
        return minTree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return minTree[node] = min(minInit(start, mid, node * 2), minInit(mid + 1, end, node * 2 + 1));
}

int minFind(int start, int end, int node, int left, int right) {
    if (right < start || end < left) {
        return INT_MAX;
    }

    if (left <= start && end <= right) {
        return minTree[node];
    }

    int mid = (start + end) / 2;

    return min(minFind(start, mid, node * 2, left, right), minFind(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    arr.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    minTree.resize(N * 4);

    minInit(1, N, 1);

    for (int i = 0; i < M; i++) {
        int left, right;
        cin >> left >> right;
        cout << minFind(1, N, 1, left, right) << "\n";
    }

    return 0;
}