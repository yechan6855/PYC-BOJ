#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> seq;
bool used[9];

void dfs(int cnt) {
    if (cnt == M) {
        for (int num: seq) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        used[i] = true;
        seq.push_back(i);
        dfs(cnt + 1);
        seq.pop_back();
        used[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    dfs(0);

    return 0;
}