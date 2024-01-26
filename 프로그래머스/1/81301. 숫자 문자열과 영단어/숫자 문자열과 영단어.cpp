#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    // 숫자에 대응되는 영단어 배열 생성
    string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // 현재 탐색 중인 문자열의 인덱스
    int idx = 0;

    // s의 끝까지 반복
    while (idx < s.size()) {
        // 현재 문자가 숫자라면
        if (isdigit(s[idx])) {
            // 해당 숫자를 정답에 추가
            answer = answer * 10 + (s[idx] - '0');
            idx++;
        } else {
            // 현재 문자가 영단어라면
            for (int i = 0; i < 10; i++) {
                // 현재 문자열이 numbers[i]와 일치하는지 확인
                if (s.substr(idx, numbers[i].size()) == numbers[i]) {
                    // 해당 숫자를 정답에 추가
                    answer = answer * 10 + i;
                    idx += numbers[i].size();
                    break;
                }
            }
        }
    }
    return answer;
}