#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n, 1);
    for (int i = 0; i < lost.size(); i++) {
        students[lost[i] - 1]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        students[reserve[i] - 1]++;
    }
    for (int i = 0; i < students.size(); i++) {
        if (students[i] == 0) {
            if (i > 0 && students[i - 1] == 2) {
                students[i - 1]--;
                students[i]++;
            } else if (i < students.size() - 1 && students[i + 1] == 2) {
                students[i + 1]--;
                students[i]++;
            }
        }
    }
    for (int i = 0; i < students.size(); i++) {
        if (students[i] > 0) {
            answer++;
        }
    }
    return answer;
}