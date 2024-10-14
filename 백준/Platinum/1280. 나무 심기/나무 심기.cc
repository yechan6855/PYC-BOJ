#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1'000'000'007;

struct SegmentTree {
    int size;
    vector<ll> tree_count;
    vector<ll> tree_sum;

    void init(int n) {
        size = 1;

        while (size < n){
            size <<= 1;
        }
        tree_count.assign(2 * size, 0LL);
        tree_sum.assign(2 * size, 0LL);
    }

    void update(int pos, ll x) {
        pos += size;
        tree_count[pos] += 1;
        tree_sum[pos] += x;
        pos /= 2;

        while (pos >= 1) {
            tree_count[pos] = tree_count[2 * pos] + tree_count[2 * pos + 1];
            tree_sum[pos] = tree_sum[2 * pos] + tree_sum[2 * pos + 1];
            pos /= 2;
        }
    }

    pair<ll, ll> query(int l, int r) {
        l += size;
        r += size;

        ll res_count = 0;
        ll res_sum = 0;

        while (l < r) {
            if (l & 1) {
                res_count += tree_count[l];
                res_sum += tree_sum[l];

                l++;
            }
            if (r & 1) {
                r--;

                res_count += tree_count[r];
                res_sum += tree_sum[r];
            }
            l /= 2;
            r /= 2;
        }
        return {res_count, res_sum};
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> X(N);
    vector<ll> sorted_X;

    for(auto &x : X){
        cin >> x;
        sorted_X.push_back(x);
    }

    sort(sorted_X.begin(), sorted_X.end());
    sorted_X.erase(unique(sorted_X.begin(), sorted_X.end()), sorted_X.end());

    auto get_idx = [&](ll x) -> int {
        return lower_bound(sorted_X.begin(), sorted_X.end(), x) - sorted_X.begin();
    };

    SegmentTree st;

    st.init(sorted_X.size());

    ll result = 1;
    ll total_sum = 0;

    for(int i=0;i<N;i++){
        if(i == 0){
            st.update(get_idx(X[i]), X[i]);
            total_sum += X[i];
        }
        else{
            int idx = get_idx(X[i]);

            pair<ll, ll> left = st.query(0, idx+1);
            pair<ll, ll> right = st.query(idx+1, st.size);

            ll cost = (X[i] * left.first - left.second) % MOD;
            cost = (cost + (right.second - X[i] * right.first)) % MOD;
            if(cost < 0) cost += MOD;

            result = (result * cost) % MOD;

            st.update(idx, X[i]);

            total_sum += X[i];
            total_sum %= MOD;
        }
    }
    cout << result;
}