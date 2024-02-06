// LIS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> LIS;  // LIS 구성하는 수열
    vector<pair<int, int>> trace;  // 인덱스 이동 기록

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);

        if (it == LIS.end()) {
            // 현재 수가 LIS의 끝보다 크다면 LIS에 추가
            LIS.push_back(A[i]);
            trace.push_back({LIS.size() - 1, i});
        } else {
            // 현재 수가 LIS의 어떤 위치에 들어가야 한다면 해당 위치에 값 갱신
            *it = A[i];
            trace.push_back({it - LIS.begin(), i});
        }
    }

    // LIS 길이 출력
    cout << LIS.size() << '\n';

    // LIS 출력
    vector<int> result;
    int idx = LIS.size() - 1;

    // trace 역추적
    for (int i = N - 1; i >= 0; --i) {
        if (trace[i].first == idx) {
            result.push_back(A[trace[i].second]);
            idx--;
        }
    }
    // 역순 출력
    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i] << ' ';
    }
    return 0;
}