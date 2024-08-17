#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAXN = 200000;
vector<pair<int, int>> tree[MAXN];
bool removed[MAXN];
int subtree_size[MAXN];
int best_result = INT_MAX;

void get_subtree_size(int node, int parent) {
    subtree_size[node] = 1;
    for (auto &edge : tree[node]) {
        int neighbor = edge.first;
        if (neighbor != parent && !removed[neighbor]) {
            get_subtree_size(neighbor, node);
            subtree_size[node] += subtree_size[neighbor];
        }
    }
}

int find_centroid(int node, int parent, int total_nodes) {
    for (auto &edge : tree[node]) {
        int neighbor = edge.first;
        if (neighbor != parent && !removed[neighbor] && subtree_size[neighbor] > total_nodes / 2) {
            return find_centroid(neighbor, node, total_nodes);
        }
    }
    return node;
}

void collect_paths(int node, int parent, int depth, int length, vector<pair<int, int>> &paths) {
    paths.push_back({length, depth});
    for (auto &edge : tree[node]) {
        int neighbor = edge.first;
        int weight = edge.second;
        if (neighbor != parent && !removed[neighbor]) {
            collect_paths(neighbor, node, depth + 1, length + weight, paths);
        }
    }
}

void process_centroid(int centroid, int required_length) {
    unordered_map<int, int> length_to_min_depth;
    length_to_min_depth[0] = 0;

    for (auto &edge : tree[centroid]) {
        int neighbor = edge.first;
        if (removed[neighbor]) continue;

        vector<pair<int, int>> paths;
        collect_paths(neighbor, centroid, 1, edge.second, paths);

        for (auto &path : paths) {
            int length = path.first;
            int depth = path.second;
            if (length == required_length) {
                best_result = min(best_result, depth);
            }
            if (length_to_min_depth.count(required_length - length)) {
                int total_depth = depth + length_to_min_depth[required_length - length];
                best_result = min(best_result, total_depth);
            }
        }

        for (auto &path : paths) {
            int length = path.first;
            int depth = path.second;
            if (length_to_min_depth.count(length)) {
                length_to_min_depth[length] = min(length_to_min_depth[length], depth);
            } else {
                length_to_min_depth[length] = depth;
            }
        }
    }
}

void decompose(int node, int required_length) {
    get_subtree_size(node, -1);
    int total_nodes = subtree_size[node];
    int centroid = find_centroid(node, -1, total_nodes);

    process_centroid(centroid, required_length);

    removed[centroid] = true;
    for (auto &edge : tree[centroid]) {
        int neighbor = edge.first;
        if (!removed[neighbor]) {
            decompose(neighbor, required_length);
        }
    }
}

int best_path(int N, int K, vector<vector<int>> &H, vector<int> &L) {
    for (auto &edges : H) {
        int u = edges[0];
        int v = edges[1];
        tree[u].emplace_back(v, L[&edges - &H[0]]);
        tree[v].emplace_back(u, L[&edges - &H[0]]);
    }

    decompose(0, K);

    return best_result == INT_MAX ? -1 : best_result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    vector<vector<int>> H(N - 1, vector<int>(2));
    vector<int> L(N - 1);

    for (int i = 0; i < N - 1; ++i) {
        cin >> H[i][0] >> H[i][1] >> L[i];
    }

    cout << best_path(N, K, H, L) << endl;
    return 0;
}