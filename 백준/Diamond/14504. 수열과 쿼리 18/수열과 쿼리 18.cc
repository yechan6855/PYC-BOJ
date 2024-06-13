#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pi pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int N, M;
vi A;
vvi buckets;
int bucket_size;

void build() {
    bucket_size = sqrt(N) + 1;
    buckets.assign(bucket_size, vi());
    for (int i = 0; i < N; ++i) {
        buckets[i / bucket_size].pb(A[i]);
    }
    for (int i = 0; i < bucket_size; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }
}

int query(int i, int j, int k) {
    int count = 0;
    int start_bucket = i / bucket_size;
    int end_bucket = j / bucket_size;

    if (start_bucket == end_bucket) {
        for (int x = i; x <= j; ++x) {
            if (A[x] > k) count++;
        }
    } else {
        for (int x = i; x < (start_bucket + 1) * bucket_size; ++x) {
            if (A[x] > k) count++;
        }
        for (int x = start_bucket + 1; x < end_bucket; ++x) {
            count += buckets[x].end() - upper_bound(buckets[x].begin(), buckets[x].end(), k);
        }
        for (int x = end_bucket * bucket_size; x <= j; ++x) {
            if (A[x] > k) count++;
        }
    }
    return count;
}

void update(int i, int k) {
    int idx = i / bucket_size;
    auto it = lower_bound(buckets[idx].begin(), buckets[idx].end(), A[i]);
    if (it != buckets[idx].end() && *it == A[i]) {
        *it = k;
        sort(buckets[idx].begin(), buckets[idx].end());
    }
    A[i] = k;
}

int main() {
    io;
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    build();

    cin >> M;
    for (int q = 0; q < M; ++q) {
        int type, i, j, k;
        cin >> type >> i >> j;
        if (type == 1) {
            cin >> k;
            cout << query(i - 1, j - 1, k) << endl;
        } else if (type == 2) {
            update(i - 1, j);
        }
    }

    return 0;
}