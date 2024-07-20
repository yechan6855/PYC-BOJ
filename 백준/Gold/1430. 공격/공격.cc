#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Node {
    double dist;
    int x, y;
};

double get_dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void solve(int start, int n, double r, double& answer, const vector<Node>& graph, double d) {
    queue<pair<int, double>> q;
    vector<bool> visited(n, false);

    q.push({start, d});
    visited[start] = true;

    while (!q.empty()) {
        auto [cur, power] = q.front();
        q.pop();

        if (graph[cur].dist <= r) {
            answer += power;
            return;
        }

        for (int nxt = 0; nxt < n; ++nxt) {
            if (get_dist(graph[nxt].x, graph[nxt].y, graph[cur].x, graph[cur].y) <= r) {
                if (!visited[nxt]) {
                    q.push({nxt, power / 2});
                    visited[nxt] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double r, d;
    int x, y;

    cin >> n >> r >> d >> x >> y;
    vector<Node> graph(n);

    for (int i = 0; i < n; ++i) {
        int _x, _y;
        cin >> _x >> _y;
        double distance = get_dist(_x, _y, x, y);
        graph[i] = {distance, _x, _y};
    }

    sort(graph.begin(), graph.end(), [](const Node& a, const Node& b) {
        return a.dist < b.dist;
    });

    double answer = 0;
    for (int i = 0; i < n; ++i) {
        solve(i, n, r, answer, graph, d);
    }
    cout << answer << endl;

    return 0;
}