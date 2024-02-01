#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;  // 무한대 값 설정

int N;
int W[16][16];  // 도시 간의 비용을 저장하는 배열
int dp[16][1 << 16];  // 동적 계획법을 위한 배열

int tsp(int current, int visited) {
    // 모든 도시를 방문한 경우
    if (visited == (1 << N) - 1) {
        // 현재 도시에서 출발 도시(0번 도시)로 가는 비용 반환
        if (W[current][0] != 0)  // 출발 도시로 가는 경로가 있는 경우
            return W[current][0];
        else
            return INF;  // 출발 도시로 가는 경로가 없는 경우
    }

    // 이미 계산한 적이 있는 경우
    if (dp[current][visited] != -1)
        return dp[current][visited];

    // 현재 도시에서 방문하지 않은 도시들을 순회하며 최소 비용 계산
    int result = INF;
    for (int next = 0; next < N; ++next) {
        if ((visited & (1 << next)) == 0 && W[current][next] != 0) {
            // 방문하지 않은 도시이고, 현재 도시에서 다음 도시로 가는 경로가 있는 경우
            int cost = W[current][next] + tsp(next, visited | (1 << next));
            result = min(result, cost);
        }
    }

    // 계산 결과를 저장하고 반환
    return dp[current][visited] = result;
}

int main() {
    // 입력 받기
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
        }
    }

    // 동적 계획법 배열 초기화
    memset(dp, -1, sizeof(dp));

    // 0번 도시에서 시작하여 모든 도시를 방문하는 최소 비용 계산
    int answer = tsp(0, 1);

    // 출력
    cout << answer << endl;

    return 0;
}