#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct Star {
    double x, y;

    Star(double x, double y) : x(x), y(y) {}
};

struct Edge {
    int from, to;
    double cost;

    Edge(int from, int to, double cost) : from(from), to(to), cost(cost) {}

    bool operator<(const Edge& other) const {
        return cost > other.cost;
    }
};

double getDistance(const Star& a, const Star& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Star> stars;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        stars.emplace_back(x, y);
    }

    priority_queue<Edge> pq;
    vector<bool> visited(n, false);
    
    visited[0] = true;
    for (int i = 1; i < n; ++i) {
        pq.push(Edge(0, i, getDistance(stars[0], stars[i])));
    }

    double result = 0;

    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();

        if (visited[edge.to]) continue;

        visited[edge.to] = true;
        result += edge.cost;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                pq.push(Edge(edge.to, i, getDistance(stars[edge.to], stars[i])));
            }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << result << "\n";

    return 0;
}