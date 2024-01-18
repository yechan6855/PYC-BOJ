#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permutation(vector<int>& nums, vector<int>& result, vector<bool>& used, int M, int depth) {
    if (depth == M) {
        for (int num : result) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            result[depth] = nums[i];
            permutation(nums, result, used, M, depth + 1);
            used[i] = false;
        }
    }
}
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    vector<int> result(M);
    vector<bool> used(N, false);

    permutation(nums, result, used, M, 0);

    return 0;
}