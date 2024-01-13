#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int flip(vector<unsigned int>& coins, int row)
{
    if (row == N)
    {
        int total = 0;
        for (int i = 0; i < N; ++i)
        {
            int col_t_cnt = 0;
            for (int j = 0; j < N; ++j)
            {
                if (coins[j] & (1 << i))
                {
                    ++col_t_cnt;
                }
            }
            total += min(col_t_cnt, N - col_t_cnt);
        }

        return total;
    }

    int unfliped_t_cnt = flip(coins, row + 1);

    coins[row] = ~coins[row];
    int fliped_t_cnt = flip(coins, row + 1);

    return min(unfliped_t_cnt, fliped_t_cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<unsigned int> coins(N);
    for (int i = 0; i < N; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < N; ++j)
        {
            if (line[j] == 'T')
            {
                coins[i] |= (1 << j);
            }
        }
    }
    cout << flip(coins, 0);
    return 0;
}