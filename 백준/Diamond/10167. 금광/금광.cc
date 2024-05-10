#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<tuple<int, int, int>> mines(N);
    vector<int> xs, ys;

    for (int i = 0; i < N; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        mines[i] = make_tuple(x, y, w);
        xs.push_back(x);
        ys.push_back(y);
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    map<int, int> x_compress, y_compress;
    for (int i = 0; i < xs.size(); i++) x_compress[xs[i]] = i;
    for (int i = 0; i < ys.size(); i++) y_compress[ys[i]] = i;

    vector<vector<int>> grid(xs.size(), vector<int>(ys.size(), 0));
    for (auto &[x, y, w] : mines) {
        int cx = x_compress[x];
        int cy = y_compress[y];
        grid[cx][cy] += w;
    }

    int max_profit = 0;
    
    for (int left = 0; left < xs.size(); ++left) {
        vector<int> profits(ys.size(), 0);
        for (int right = left; right < xs.size(); ++right) {
            for (int k = 0; k < ys.size(); ++k) {
                profits[k] += grid[right][k];
            }

            int local_max = 0, current_sum = 0;
            for (int profit : profits) {
                current_sum = max(current_sum + profit, profit);
                local_max = max(local_max, current_sum);
            }
            max_profit = max(max_profit, local_max);
        }
    }

    cout << max_profit << endl;
    return 0;
}