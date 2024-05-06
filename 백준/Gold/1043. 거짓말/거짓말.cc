/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1043                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: red6855 <boj.kr/u/red6855>                  +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1043                           #+#        #+#      #+#    */
/*   Solved: 2024/05/06 17:21:06 by red6855       ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M, K;
vector<int> truth;
vector<vector<int>> party;
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) parent[i] = i;

    cin >> K;
    truth.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> truth[i];
    }

    party.resize(M);
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        party[i].resize(num);
        for (int j = 0; j < num; j++) {
            cin >> party[i][j];
            if (j > 0) merge(party[i][j - 1], party[i][j]);
        }
    }

    int answer = 0;
    for (int i = 0; i < M; i++) {
        bool isLie = false;
        for (int j = 0; j < party[i].size(); j++) {
            for (int k = 0; k < truth.size(); k++) {
                if (find(party[i][j]) == find(truth[k])) {
                    isLie = true;
                    break;
                }
            }
            if (isLie) break;
        }
        if (!isLie) answer++;
    }

    cout << answer << endl;
    return 0;
}