#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> result;

void dfs(int depth, int start) {
    if (depth == M) {
        for (int num : result) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    int prev_num = -1;  // 중복된 수열을 허용하기 위해 이전에 선택한 숫자를 기록
    for (int i = start; i < N; ++i) {
        if (prev_num != numbers[i]) {
            result.push_back(numbers[i]);
            dfs(depth + 1, i);
            result.pop_back();
            prev_num = numbers[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    numbers.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());

    dfs(0, 0);

    return 0;
}