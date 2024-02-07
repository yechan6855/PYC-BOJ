#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    // 무게추를 정렬
    sort(weights.begin(), weights.end());

    int answer = 1; // 가장 작은 측정할 수 없는 무게 초기값은 1

    // 현재까지 측정할 수 있는 무게까지의 합 + 1이 다음 무게추보다 크거나 같으면 무게 추가 가능
    for (int i = 0; i < n; ++i) {
        if (answer >= weights[i]) {
            answer += weights[i];
        } else {
            break;
        }
    }

    cout << answer << endl;

    return 0;
}