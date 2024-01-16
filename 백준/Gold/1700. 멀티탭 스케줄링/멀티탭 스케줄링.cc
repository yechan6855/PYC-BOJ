#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, M;
set<int> Tab;
vector<int> Schedule;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i)
    {
        int _input;
        cin >> _input;

        Schedule.push_back(_input);
    }
    int ans = 0;

    for (int i = 0; i < M; ++i)
    {
        int Cur = Schedule[i];

        if (Tab.size() < N)
        {
            Tab.insert(Cur);
            continue;
        }
        if (Tab.find(Cur) != Tab.end())
            continue;
        int LastIdx = -1;
        auto ToPop = Tab.begin();
        for (auto iter = Tab.begin(); iter != Tab.end(); ++iter)
        {
            int CurIdx = 0;
            int Can = *iter;
            bool Found = false;
            for (int j = i+1; j < M; ++j)
            {
                if (Schedule[j] == Can)
                {
                    Found = true;
                    CurIdx = j;
                    break;
                }
            }
            if (!Found)
                CurIdx = M;

            if (LastIdx < CurIdx)
            {
                LastIdx = CurIdx;
                ToPop = iter;
            }
        }
        Tab.erase(ToPop);
        Tab.insert(Cur);
        ans++;
    }
    cout << ans;
    return 0;
}