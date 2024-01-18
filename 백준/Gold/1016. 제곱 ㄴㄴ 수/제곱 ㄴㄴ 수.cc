#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    long long min, max;
    cin >> min >> max;

    vector<bool> isNotSquare(max - min + 1, false); // min부터 max까지의 범위에서 각 수가 제곱수의 배수인지를 나타내는 벡터

    long long limit = (long long)sqrt(max); // 범위 내의 제곱수의 최대값 계산

    for (long long i = 2; i <= limit; ++i) { // 에라토스테네스의 체를 응용하여 제곱수의 배수인 수를 체크
        long long square = i * i;
        long long start = (min / square) * square;
        if (start < min)
            start += square;

        for (long long j = start; j <= max; j += square) { // 제곱수의 배수인 수를 체크
            isNotSquare[j - min] = true;
        }
    }
    int count = 0; // 제곱수의 배수가 아닌 수의 개수 세기
    for (bool notSquare : isNotSquare) {
        if (!notSquare)
            count++;
    }
    cout << count << endl; // 결과 출력

    return 0;
}