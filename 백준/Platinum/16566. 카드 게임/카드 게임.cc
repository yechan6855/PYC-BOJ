#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> cards(M);
    for (int i = 0; i < M; i++) {
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());

    parent.resize(M + 1);
    for (int i = 0; i <= M; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < K; i++) {
        int cheolsu;
        cin >> cheolsu;

        int idx = upper_bound(cards.begin(), cards.end(), cheolsu) - cards.begin();
        idx = find(idx);

        cout << cards[idx] << '\n';

        if (idx < M - 1) {
            unite(idx, idx + 1);
        }
    }

    return 0;
}