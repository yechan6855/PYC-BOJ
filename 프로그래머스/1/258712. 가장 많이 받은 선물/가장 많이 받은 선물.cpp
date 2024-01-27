#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, char dlim)
{
	vector<string> result;

	stringstream ss;
	string stringBuffer;
	ss.str(input);
	
	while (getline(ss, stringBuffer, dlim))	
	{
		result.push_back(stringBuffer);
	}

	return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, int> friendDic;
    vector<int> giftIndex(friends.size());
    vector<vector<int>> giftRecord(friends.size(), vector<int>(friends.size(), 0));
    
    for(int i = 0; i < friends.size(); i++)
    {
        friendDic.emplace(friends[i], i);
    }
    for(string str : gifts)
    {
        vector<string> v = split(str, ' ');
        giftRecord[friendDic[v[0]]][friendDic[v[1]]]++;
        giftIndex[friendDic[v[0]]]++;
        giftIndex[friendDic[v[1]]]--;
    }
    
    int cnt;
    for(int i = 0; i < friends.size(); i++)
    {
        cnt = 0;
        for(int j = 0; j < friends.size(); j++)
        {
            if(i == j)
                continue;
            if(giftRecord[i][j] > giftRecord[j][i])
            {
                cnt++;
            }else if(giftRecord[i][j] == giftRecord[j][i])
            {
                if(giftIndex[i] > giftIndex[j])
                {
                    cnt++;
                }
            }
        }
        answer = max(answer, cnt);
    }
    return answer;
}