#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> problems(N);
    for (int i = 0; i < N; ++i) {
        cin >> problems[i].first >> problems[i].second; // first: deadline, second: cup noodles
    }

    // 데드라인에 따라 문제를 정렬
    sort(problems.begin(), problems.end());

    priority_queue<int, vector<int>, greater<int>> pq; // 컵라면 수에 따른 최소 힙

    for (int i = 0; i < N; ++i) {
        pq.push(problems[i].second); // 문제를 우선순위 큐에 추가
        while (pq.size() > problems[i].first) {
            pq.pop(); // 데드라인을 초과하는 경우, 컵라면 수가 가장 적은 문제 제거
        }
    }

    // 우선순위 큐에 남은 문제들의 컵라면 수의 합
    int result = 0;
    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }

    cout << result;
    return 0;
}