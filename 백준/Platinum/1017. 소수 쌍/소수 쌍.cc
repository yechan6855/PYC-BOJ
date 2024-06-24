#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

const int MAXN = 50;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

bool bpm(int u, vvi &bpGraph, vi &matchR, vi &seen) {
    for (int v = 0; v < bpGraph[u].size(); ++v) {
        if (bpGraph[u][v] && !seen[v]) {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v], bpGraph, matchR, seen)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(vvi &bpGraph) {
    vi matchR(bpGraph[0].size(), -1);
    int result = 0;
    for (int u = 0; u < bpGraph.size(); u++) {
        vi seen(bpGraph[0].size(), 0);
        if (bpm(u, bpGraph, matchR, seen))
            result++;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vi nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    if (n == 2) {
        if (isPrime(nums[0] + nums[1])) {
            cout << nums[1] << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }

    vi firstMatches;
    for (int i = 1; i < n; ++i) {
        if (isPrime(nums[0] + nums[i])) {
            firstMatches.pb(i);
        }
    }

    vi result;
    for (int k : firstMatches) {
        vi leftSet, rightSet;

        for (int i = 1; i < n; ++i) {
            if (i == k) continue;
            if ((nums[i] % 2) == (nums[0] % 2)) {
                leftSet.pb(i);
            } else {
                rightSet.pb(i);
            }
        }

        if (leftSet.size() != rightSet.size()) continue;

        int size = leftSet.size();
        vvi bpGraph(size, vi(size, 0));

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (isPrime(nums[leftSet[i]] + nums[rightSet[j]])) {
                    bpGraph[i][j] = 1;
                }
            }
        }

        if (maxBPM(bpGraph) == size) {
            result.pb(nums[k]);
        }
    }

    if (result.empty()) {
        cout << -1 << endl;
    } else {
        sort(result.begin(), result.end());
        for (int r : result) {
            cout << r << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    io;
    solve();
    return 0;
}