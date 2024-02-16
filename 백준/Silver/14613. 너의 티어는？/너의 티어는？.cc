#include <iostream>
#include <iomanip>
using namespace std;

double dp[21][3501]; // dp[i][j] : i번째 경기에서 j점을 얻을 확률

int main() {
    double W, L, D;
    cin >> W >> L >> D;

    dp[0][2000] = 1.0; // 초기 점수

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j <= 3500; j += 50) {
            if (dp[i][j] > 0) {
                dp[i + 1][j + 50] += dp[i][j] * W; // 승리
                dp[i + 1][j - 50] += dp[i][j] * L; // 패배
                dp[i + 1][j] += dp[i][j] * D; // 무승부
            }
        }
    }

    double bronze = 0, silver = 0, gold = 0, platinum = 0, diamond = 0; // 각 리그별 확률
    for (int i = 1000; i <= 3499; i += 50) { // 1000 ~ 3499점까지
        if (i < 1500) bronze += dp[20][i]; // 1500점 미만이면 브론즈
        else if (i < 2000) silver += dp[20][i]; // 2000점 미만이면 실버
        else if (i < 2500) gold += dp[20][i]; // 2500점 미만이면 골드
        else if (i < 3000) platinum += dp[20][i]; // 3000점 미만이면 플래티넘
        else diamond += dp[20][i]; // 3000점 이상이면 다이아몬드
    }

    cout << fixed << setprecision(8); // 소수점 8자리까지 출력
    cout << bronze << '\n' << silver << '\n' << gold << '\n' << platinum << '\n' << diamond << endl;

    return 0;
}