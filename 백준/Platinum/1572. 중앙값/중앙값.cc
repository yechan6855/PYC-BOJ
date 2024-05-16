#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int MAX_VAL = 65536;

class FenwickTree {
private:
    vector<int> tree;
    int size;

public:
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    int findKth(int k) {
        int left = 1;
        int right = size;
        while (left < right) {
            int mid = (left + right) / 2;
            if (query(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> temperatures(N);
    for (int i = 0; i < N; ++i) {
        cin >> temperatures[i];
    }

    FenwickTree fenwickTree(MAX_VAL);
    long long sumOfMedians = 0;

    for (int i = 0; i < K - 1; ++i) {
        fenwickTree.update(temperatures[i] + 1, 1);
    }

    for (int i = K - 1; i < N; ++i) {
        fenwickTree.update(temperatures[i] + 1, 1);
        int median = fenwickTree.findKth((K + 1) / 2) - 1;
        sumOfMedians += median;
        fenwickTree.update(temperatures[i - K + 1] + 1, -1);
    }

    cout << sumOfMedians << endl;
    return 0;
}