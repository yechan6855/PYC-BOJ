#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int minTransfers(vector<vector<int>>& subway, int start, int end) {
    unordered_map<int, unordered_set<int>> stationToLines;
    for (int i = 0; i < subway.size(); ++i) {
        for (int station : subway[i]) {
            stationToLines[station].insert(i);
        }
    }
    
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        int station = q.front().first;
        int transfers = q.front().second;
        q.pop();

        if (station == end) {
            return transfers;
        }

        for (int line : stationToLines[station]) {
            for (int nextStation : subway[line]) {
                if (visited.find(nextStation) == visited.end()) {
                    q.push({nextStation, transfers + (station == start ? 0 : 1)});
                    visited.insert(nextStation);
                }
            }
        }
    }

    return -1;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> subway(N);
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        subway[i].resize(K);
        for (int j = 0; j < K; ++j) {
            cin >> subway[i][j];
        }
    }

    int end;
    cin >> end;

    int start = 0;

    cout << minTransfers(subway, start, end) << endl;

    return 0;
}