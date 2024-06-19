#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, vector<vector<pii>>& graph, vi& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d, u;
        tie(d, u) = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.fi;
            int weight = edge.se;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

class SegmentTree {
public:
    SegmentTree(int size) : n(size) {
        minDist = vector<int>(4 * size, INF);
    }

    void update(int pos, int value) {
        updateUtil(0, n - 1, pos, value, 0);
    }

    int query(int left, int right) {
        return queryUtil(0, n - 1, left, right, 0);
    }

private:
    vi minDist;
    int n;

    void updateUtil(int start, int end, int pos, int value, int node) {
        if (start == end) {
            minDist[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (pos <= mid) {
                updateUtil(start, mid, pos, value, 2 * node + 1);
            } else {
                updateUtil(mid + 1, end, pos, value, 2 * node + 2);
            }
            minDist[node] = min(minDist[2 * node + 1], minDist[2 * node + 2]);
        }
    }

    int queryUtil(int start, int end, int left, int right, int node) {
        if (left > end || right < start) {
            return INF;
        }
        if (left <= start && right >= end) {
            return minDist[node];
        }
        int mid = (start + end) / 2;
        return min(queryUtil(start, mid, left, right, 2 * node + 1),
                   queryUtil(mid + 1, end, left, right, 2 * node + 2));
    }
};

int main() {
    io;
    int N, A, B, C, M, T;
    cin >> N >> A >> B >> C >> M;

    vector<vector<pii>> graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        graph[X].pb({Y, Z});
        graph[Y].pb({X, Z});
    }

    vi distA(N + 1, INF), distB(N + 1, INF), distC(N + 1, INF);

    dijkstra(A, graph, distA);
    dijkstra(B, graph, distB);
    dijkstra(C, graph, distC);

    cin >> T;

    vector<tuple<int, int, int, int>> candidates;
    for (int i = 1; i <= N; ++i) {
        candidates.pb({distA[i], distB[i], distC[i], i});
    }

    sort(candidates.begin(), candidates.end());

    SegmentTree segTree(N);

    for (const auto& [a, b, c, idx] : candidates) {
        segTree.update(idx - 1, c);
    }

    vector<string> results(T);
    for (int i = 0; i < T; ++i) {
        int Q;
        cin >> Q;

        int a = distA[Q], b = distB[Q], c = distC[Q];
        bool can_place = true;

        for (const auto& [da, db, dc, idx] : candidates) {
            if (idx == Q) break;
            if (da < a && db < b && dc < c) {
                can_place = false;
                break;
            }
        }

        results[i] = can_place ? "YES" : "NO";
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}