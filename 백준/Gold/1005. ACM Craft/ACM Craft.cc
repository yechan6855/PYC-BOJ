#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve(void);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++)
        solve();
}
bool can_build(int idx, vector<vector<int>>& need_buildings, vector<bool>& built)
{
    vector<int> needs = need_buildings[idx];
    if (needs.empty()) return true;

    for (int n : needs)
        if (!built[n]) return false;
    return true;
}
void solve(void)
{
    int n, k;
    cin >> n >> k;

    vector<int> time(n);
    for (int& t : time)
        cin >> t;

    vector<vector<int>> next_buildings(n);
    vector<vector<int>> need_buildings(n);
    for (int i = 0; i < k; i++)
    {
        int s, e;
        cin >> s >> e;
        next_buildings[s - 1].push_back(e - 1);
        need_buildings[e - 1].push_back(s - 1);
    }
    vector<bool> built(n), on_progress(n);
    queue<pair<int, int>> building_queue;
    for (int i = 0; i < n; i++)
        if (need_buildings[i].empty())
        {
            building_queue.push(make_pair(i, time[i]));
            on_progress[i] = true;
        }

    int target;
    cin >> target;

    int total_time = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    while (!building_queue.empty() && !built[target - 1])
    {
        int limit = building_queue.size();
        for (int i = 0; i < limit; i++)
        {
            int idx, time;
            idx = building_queue.front().first;
            time = building_queue.front().second;
            building_queue.pop();

            if (can_build(idx, need_buildings, built))
                pq.push(make_pair(time, idx));
            else
                building_queue.push(make_pair(idx, time));
        }
        int smallest_time, smallest_idx;
        smallest_time = pq.top().first;
        smallest_idx = pq.top().second;
        pq.pop();
        total_time += smallest_time;

        built[smallest_idx] = true;
        for (int i = 0; i < next_buildings[smallest_idx].size(); i++)
        {
            int next_idx = next_buildings[smallest_idx][i];
            if (!on_progress[next_idx])
            {
                building_queue.push(make_pair(next_idx, time[next_idx]));
                on_progress[next_idx] = true;
            }
        }
        limit = pq.size();
        for (int j = 0; j < limit; j++)
        {
            int remain_time, idx;
            remain_time = pq.top().first;
            idx = pq.top().second;
            pq.pop();
            if (smallest_time < remain_time)
            {
                building_queue.push(make_pair(idx, remain_time - smallest_time));
                continue;
            }
            built[idx] = true;
            for (int i = 0; i < next_buildings[idx].size(); i++)
            {
                int next_idx = next_buildings[idx][i];
                if (!on_progress[next_idx])
                {
                    building_queue.push(make_pair(next_idx, time[next_idx]));
                    on_progress[next_idx] = true;
                }
            }
        }
    }
    cout << total_time << '\n';
}