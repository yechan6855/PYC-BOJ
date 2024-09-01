#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, idx;
};

bool mo_cmp(const Query& a, const Query& b) {
    int block_size = sqrt(100000);
    if (a.l / block_size != b.l / block_size) {
        return a.l / block_size < b.l / block_size;
    }
    return a.r < b.r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }

    vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end(), mo_cmp);

    vector<int> answer(Q);
    vector<int> freq(200001, 0);
    vector<int> cnt_freq(N + 1, 0);

    int cur_l = 0, cur_r = -1, max_freq = 0;

    auto add = [&](int idx) {
        int value = p[idx] + 100000;
        int old_freq = freq[value];
        int new_freq = old_freq + 1;

        freq[value] = new_freq;

        cnt_freq[old_freq]--;
        cnt_freq[new_freq]++;

        max_freq = max(max_freq, new_freq);
    };

    auto remove = [&](int idx) {
        int value = p[idx] + 100000;
        int old_freq = freq[value];
        int new_freq = old_freq - 1;

        freq[value] = new_freq;

        cnt_freq[old_freq]--;
        cnt_freq[new_freq]++;

        if (cnt_freq[max_freq] == 0) {
            max_freq--;
        }
    };

    for (const auto& q : queries) {
        while (cur_r < q.r) add(++cur_r);
        while (cur_r > q.r) remove(cur_r--);
        while (cur_l < q.l) remove(cur_l++);
        while (cur_l > q.l) add(--cur_l);

        answer[q.idx] = max_freq;
    }

    for (int ans : answer) {
        cout << ans << '\n';
    }

    return 0;
}