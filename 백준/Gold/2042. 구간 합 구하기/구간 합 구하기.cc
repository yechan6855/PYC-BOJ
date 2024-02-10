#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;
vector<long long> tree;

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    }
}

void update(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) {
        return;
    }

    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    arr.resize(N + 1);
    tree.resize(4 * (N + 1));

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    init(1, 1, N);

    for (int i = 0; i < M + K; ++i) {
        int a;
        cin >> a;

        if (a == 1) {
            int b;
            long long c;
            cin >> b >> c;
            long long diff = c - arr[b];
            arr[b] = c;
            update(1, 1, N, b, diff);
        } else if (a == 2) {
            int b, c;
            cin >> b >> c;
            cout << sum(1, 1, N, b, c) << '\n';
        }
    }
    return 0;
}