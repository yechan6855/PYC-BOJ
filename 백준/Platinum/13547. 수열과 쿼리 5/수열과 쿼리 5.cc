#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

struct Query {
    int l, r, idx;
};

int block_size;
vi result;
vi arr;
unordered_map<int, int> freq;
int distinct_count = 0;

bool compare(Query a, Query b) {
    int block_a = a.l / block_size;
    int block_b = b.l / block_size;
    if (block_a != block_b)
        return block_a < block_b;
    return a.r < b.r;
}

void add(int pos) {
    freq[arr[pos]]++;
    if (freq[arr[pos]] == 1)
        distinct_count++;
}

void remove(int pos) {
    if (freq[arr[pos]] == 1)
        distinct_count--;
    freq[arr[pos]]--;
}

int main() {
    io;
    int n, m;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> m;
    vector<Query> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].idx = i;
    }

    block_size = static_cast<int>(sqrt(n));
    sort(queries.begin(), queries.end(), compare);

    result.resize(m);
    int curr_l = 0, curr_r = -1;
    for (const auto& q : queries) {
        while (curr_l > q.l) add(--curr_l);
        while (curr_r < q.r) add(++curr_r);
        while (curr_l < q.l) remove(curr_l++);
        while (curr_r > q.r) remove(curr_r--);

        result[q.idx] = distinct_count;
    }

    for (const auto& res : result) {
        cout << res << endl;
    }

    return 0;
}