#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (auto vec : queries)
    {
        int val = 1000001;
        for (int i = vec[0]; i <= vec[1]; i++)
        {
            if (arr[i] <= vec[2])
                continue;
            val = min(val, arr[i]);
        }
        if (val == 1000001)
            val = -1;
        answer.push_back(val);
    }
    return answer;
}