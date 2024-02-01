#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 중복 제거를 위해 set을 사용
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

    // 각 수의 압축된 좌표를 저장할 맵
    map<int, int> compressionMap;
    for (int i = 0; i < sortedArr.size(); i++) {
        compressionMap[sortedArr[i]] = i;
    }

    // 각 수의 압축된 좌표를 출력
    for (int i = 0; i < n; i++) {
        cout << compressionMap[arr[i]] << " ";
    }
    return 0;
}