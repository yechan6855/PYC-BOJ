#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pi pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int blockSize;
vi freq, freqCnt;
int MaxFreq = 0;

struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        if (l / blockSize != other.l / blockSize)
            return l / blockSize < other.l / blockSize;
        return r < other.r;
    }
};


void add(int value) {
    int curFreq = freq[value];
    freqCnt[curFreq]--;
    freq[value]++;
    freqCnt[freq[value]]++;
    if (freqCnt[MaxFreq + 1] > 0) {
        MaxFreq++;
    }
}

void remove(int value) {
    int currentFreq = freq[value];
    freqCnt[currentFreq]--;
    freq[value]--;
    freqCnt[freq[value]]++;
    if (freqCnt[MaxFreq] == 0) {
        MaxFreq--;
    }
}

int main() {
    io;
    int N;
    cin >> N;
    vi arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int M;
    cin >> M;
    vector<Query> queries(M);
    vi answers(M);
    blockSize = static_cast<int>(sqrt(N));

    for (int i = 0; i < M; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    freq.resize(100001);
    freqCnt.resize(N + 1);

    int curL = 0, curR = -1;

    for (const auto& query : queries) {
        while (curR < query.r) {
            curR++;
            add(arr[curR]);
        }
        while (curR > query.r) {
            remove(arr[curR]);
            curR--;
        }
        while (curL < query.l) {
            remove(arr[curL]);
            curL++;
        }
        while (curL > query.l) {
            curL--;
            add(arr[curL]);
        }
        answers[query.idx] = MaxFreq;
    }

    for (const auto& answer : answers) {
        cout << answer << endl;
    }

    return 0;
}