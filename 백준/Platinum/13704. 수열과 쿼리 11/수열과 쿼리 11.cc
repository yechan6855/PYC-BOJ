#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, idx, block;
};

bool mo_cmp(const Query &a, const Query &b) {
    if (a.block != b.block) return a.block < b.block;
    return (a.block & 1) ? a.r > b.r : a.r < b.r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    vector<int> A(N);
    for (auto &x : A) cin >> x;

    vector<long long> P(N+1, 0);
    for (int i = 1; i <= N; i++) P[i] = P[i-1] ^ A[i-1];

    int M;
    cin >> M;

    vector<Query> queries(M);
    int block_size = static_cast<int>(sqrt(N)) + 1;
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l-1, r, i, (l-1) / block_size};
    }

    sort(queries.begin(), queries.end(), mo_cmp);

    const int MAX_P = (1 << 20);
    vector<int> freq(MAX_P, 0);

    int currentL = 0, currentR = 0;
    freq[P[0]] = 1;
    long long count = 0;

    vector<long long> answers(M, 0);

    for (auto &q : queries) {
        while (currentR < q.r) {
            currentR++;
            if (currentR > N) break;
            count += freq[P[currentR] ^ K];
            freq[P[currentR]]++;
        }
        while (currentR > q.r) {
            freq[P[currentR]]--;
            count -= freq[P[currentR] ^ K];
            currentR--;
        }
        while (currentL > q.l) {
            currentL--;
            count += freq[P[currentL] ^ K];
            freq[P[currentL]]++;
        }
        while (currentL < q.l) {
            freq[P[currentL]]--;
            count -= freq[P[currentL] ^ K];
            currentL++;
        }
        answers[q.idx] = count;
    }

    for (int i = 0; i < M; i++){
        cout << answers[i] << "\n";
    }
}