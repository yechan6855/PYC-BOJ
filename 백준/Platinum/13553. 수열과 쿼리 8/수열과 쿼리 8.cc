#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

ll sqrtn;

struct Query {
    ll index, start, end;
    bool operator < (const Query& other) const {
        if (start / sqrtn != other.start / sqrtn) return start < other.start;
        return end < other.end;
    }
};
template<size_t size>
struct FenwickTree {
    vector<ll> BIT;
    FenwickTree() : BIT(size + 1) {}
    void update(ll index, ll value) {
        for (; index <= size; index += index & -index) BIT[index] += value;
    }
    ll query(ll index) {
        if (index < 1) return 0;
        if (index > size) index = size;
        ll result = 0;
        for (; index; index -= index & -index) result += BIT[index];
        return result;
    }
};

FenwickTree<100000> fenwick;

int main() {
    io;
    ll n, k; cin >> n >> k;
    sqrtn = sqrt(n);
    vector<ll> array(n);
    for (ll i = 0; i < n; i++) cin >> array[i];

    ll q; cin >> q;
    vector<Query> queries(q);
    for (ll i = 0; i < q; i++) {
        ll left, right; cin >> left >> right;
        queries[i] = { i, --left, --right };
    }
    sort(queries.begin(), queries.end());

    vector<ll> results(q);
    ll current_value = 0, start_index = queries[0].start, end_index = start_index - 1;
    auto add = [&](int i) {
        current_value += fenwick.query(array[i] + k) - fenwick.query(array[i] - k - 1);
        fenwick.update(array[i], 1);
    };
    auto remove = [&](int i) {
        fenwick.update(array[i], -1);
        current_value -= fenwick.query(array[i] + k) - fenwick.query(array[i] - k - 1);
    };
    for (ll i = 0; i < q; i++) {
        while (queries[i].start < start_index) add(--start_index);
        while (queries[i].start > start_index) remove(start_index++);
        while (queries[i].end > end_index) add(++end_index);
        while (queries[i].end < end_index) remove(end_index--);
        results[queries[i].index] = current_value;
    }
    for (auto result : results) cout << result << endl;
}