#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> land(N, vector<int>(M));
    int maxHeight = 0;
    int minHeight = 256;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> land[i][j];
            maxHeight = max(maxHeight, land[i][j]);
            minHeight = min(minHeight, land[i][j]);
        }
    }

    int ansTime = 2e9;
    int ansHeight = 0;

    for(int height = minHeight; height <= maxHeight; height++) {
        int inventory = B;
        int time = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                int diff = land[i][j] - height;

                if(diff > 0) {
                    time += diff * 2;
                    inventory += diff;
                }
                else if(diff < 0) {
                    time += -diff;
                    inventory += diff;
                }
            }
        }

        if(inventory >= 0) {
            if(time <= ansTime) {
                ansTime = time;
                ansHeight = height;
            }
        }
    }

    cout << ansTime << " " << ansHeight;

    return 0;
}