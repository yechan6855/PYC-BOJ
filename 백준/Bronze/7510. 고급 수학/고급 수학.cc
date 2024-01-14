#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // 테스트 케이스의 수

    for (int i = 1; i <= t; ++i) {
        int sides[3];
        cin >> sides[0] >> sides[1] >> sides[2];

        sort(sides, sides + 3); // 세 변의 길이를 정렬

        cout << "Scenario #" << i << ":\n";

        // 삼각형의 성립 조건 확인
        if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
            cout << "yes\n\n";
        } else {
            cout << "no\n\n";
        }
    }
    return 0;
}