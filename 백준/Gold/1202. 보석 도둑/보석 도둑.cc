#include <iostream>
#include <set>
#include <climits>
#include <iterator>
#include <algorithm>

using namespace std;

#define w first
#define v second
#define MAX 300010

multiset<pair<int, int>> gems;
multiset<int> avail;
int bags[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        pair<int, int> gem;
        cin >> gem.w >> gem.v;
        gems.insert(gem);
    }

    for (int i = 0; i < k; i++)
        cin >> bags[i];

    sort(bags, bags + k);

    long long ans = 0;

    for (int i = 0; i < k; i++) {
        int cap = bags[i];
        auto upper = gems.upper_bound({cap, INT_MAX});

        for (auto iter = gems.begin(); iter != upper;) {
            avail.insert((*iter).v);
            iter = gems.erase(iter);
        }

        if (avail.size() > 0) {
            int m = *prev(avail.end());
            avail.erase(prev(avail.end()));
            ans += m;
        }
    }

    cout << ans << "\n";

    return 0;
}