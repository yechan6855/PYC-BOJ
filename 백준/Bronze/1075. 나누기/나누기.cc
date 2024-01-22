// 입력값의 크기가 너무 커서 정수형으로 입력받기 힘듬
// 문자열로 입력받아서 정수형으로 변환해야함

#include <iostream>
#include <string>

using namespace std;

int main() {
    // 문자열로 입력 받기
    string str_N, str_F;
    cin >> str_N >> str_F;

    // 문자열을 정수로 변환
    int N = stoi(str_N);
    int F = stoi(str_F);

    // N의 뒷자리 두 자리를 00부터 99까지 바꿔가며 F로 나누어 떨어지는지 확인
    for (int i = 0; i < 100; ++i) {
        N = (N / 100) * 100 + i;  // 뒷자리 두 자리를 바꿔주기
        if (N % F == 0) {
            // 결과를 문자열로 출력
            string result = (i < 10) ? "0" + to_string(i) : to_string(i);
            cout << result << endl;
            break;
        }
    }
    return 0;
}