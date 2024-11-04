#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Query {
    int l, r, idx;
};

struct BIT {
    int size;
    vector<int> tree;

    BIT(int n) : size(n), tree(n + 1, 0) {}

    void update(int idx, int delta) {
        while (idx <= size) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) const {
        int res = 0;
        int i = idx;
        while (i > 0) {
            res += tree[i];
            i -= i & -i;
        }
        return res;
    }

    int query(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(auto &x : A) cin >> x;

    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    sorted_A.erase(unique(sorted_A.begin(), sorted_A.end()), sorted_A.end());

    auto get_compressed = [&](int x) -> int {
        return lower_bound(sorted_A.begin(), sorted_A.end(), x) - sorted_A.begin() + 1;
    };
    vector<int> compressed_A(N);
    for(int i = 0; i < N; ++i){
        compressed_A[i] = get_compressed(A[i]);
    }

    vector<Query> queries(M);
    for(int i = 0; i < M; ++i){
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    int block_size = sqrt(N) + 1;
    sort(queries.begin(), queries.end(), [&](const Query &a, const Query &b) -> bool{
        int block_a = (a.l - 1) / block_size;
        int block_b = (b.l - 1) / block_size;
        if(block_a != block_b) return block_a < block_b;
        if(block_a & 1) return a.r < b.r;
        else return a.r > b.r;
    });

    vector<ll> res(M, 0);

    BIT bit(sorted_A.size());

    int currL = 1, currR = 0;
    ll inversion = 0;

    for(auto &q : queries){
        int L = q.l;
        int R = q.r;

        while(currR < R){
            currR++;
            int val = compressed_A[currR - 1];

            inversion += bit.query(sorted_A.size()) - bit.query(val);
            bit.update(val, 1);
        }
        while(currR > R){
            int val = compressed_A[currR - 1];
            bit.update(val, -1);
            inversion -= bit.query(sorted_A.size()) - bit.query(val);
            currR--;
        }

        while(currL < L){
            int val = compressed_A[currL - 1];
            bit.update(val, -1);
            inversion -= bit.query(val - 1);
            currL++;
        }
        while(currL > L){
            currL--;
            int val = compressed_A[currL - 1];
            inversion += bit.query(val - 1);
            bit.update(val, 1);
        }

        res[q.idx] = inversion;
    }

    for(int i = 0; i < M; ++i){
        cout << res[i] << "\n";
    }
}