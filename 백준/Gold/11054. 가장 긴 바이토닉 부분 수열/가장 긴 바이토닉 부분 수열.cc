#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> dp_increase(N, 1);  // 증가하는 부분 수열의 길이를 저장하는 배열
    vector<int> dp_decrease(N, 1);  // 감소하는 부분 수열의 길이를 저장하는 배열

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // 증가하는 부분 수열의 길이 계산
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp_increase[i] = max(dp_increase[i], dp_increase[j] + 1);
            }
        }
    }

    // 감소하는 부분 수열의 길이 계산
    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j > i; --j) {
            if (arr[i] > arr[j]) {
                dp_decrease[i] = max(dp_decrease[i], dp_decrease[j] + 1);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i) {
        // 가장 긴 바이토닉 부분 수열의 길이는 증가하는 부분과 감소하는 부분의 합에서 1을 뺀 값
        answer = max(answer, dp_increase[i] + dp_decrease[i] - 1);
    }
    cout << answer << '\n';

    return 0;
}