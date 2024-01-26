#include <algorithm>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    int left = 1;
    int right = distance;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        int removeCount = 0;
        int prevRock = 0;
        for (int i = 0; i < rocks.size(); i++) {
            if (rocks[i] - prevRock < mid) {
                removeCount++;
            } else {
                prevRock = rocks[i];
            }
        }
        
        if (distance - prevRock < mid) {
            removeCount++;
        }
        
        if (removeCount <= n) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}