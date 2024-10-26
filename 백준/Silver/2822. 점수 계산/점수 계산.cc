#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> scores(8);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 8; i++) {
        scores[i].second = i + 1;
        cin >> scores[i].first;
    }

    sort(scores.begin(), scores.end(), greater<pair<int, int>>());

    int sum = 0;
    vector<int> select;
    for(int i = 0; i < 5; i++) {
        sum += scores[i].first;
        select.push_back(scores[i].second);
    }

    sort(select.begin(), select.end());

    cout << sum << '\n';
    for(int i = 0; i < 5; i++) {
        cout << select[i] << ' ';
    }

    return 0;
}