#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define pii pair<int, int>
#define vi vector<int>
#define qi queue<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

struct Container {
    int priority;
    int weight;
};

bool compare(const pii &a, const pii &b) {
    return a.fi > b.fi;
}

int32_t main() {
    io;
    int n, m;
    cin >> n >> m;

    vector<Container> containers(n);
    for (int i = 0; i < n; ++i) {
        cin >> containers[i].priority >> containers[i].weight;
    }

    queue<Container> q;
    map<int, int> priority_map;

    for (const auto &container : containers) {
        q.push(container);
        priority_map[container.priority]++;
    }

    vector<pii> priority_list(priority_map.begin(), priority_map.end());
    sort(priority_list.begin(), priority_list.end(), compare);

    vector<Container> result_stack;
    vector<Container> last_stack;
    int cost = 0;

    while (!q.empty()) {
        Container now = q.front();
        q.pop();

        if (priority_list[0].fi == now.priority) {
            while (!result_stack.empty() && result_stack.back().priority == now.priority && result_stack.back().weight < now.weight) {
                Container go = result_stack.back();
                result_stack.pop_back();
                cost += go.weight;
                last_stack.pb(go);
            }
            result_stack.pb(now);
            cost += now.weight;
            while (!last_stack.empty()) {
                Container go = last_stack.back();
                last_stack.pop_back();
                cost += go.weight;
                result_stack.pb(go);
            }

            priority_list[0].se--;
            if (priority_list[0].se == 0) {
                priority_list.erase(priority_list.begin());
            }
        } else {
            q.push(now);
            cost += now.weight;
        }
    }

    cout << cost << endl;
    return 0;
}