#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define Large 1000000000
#define Large_Size 9

ll n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector <ll> d = { 1 };
    
    cin >> n;
    for (ll i = 1; i * 2 <= n; i++)
    {
        ll mul = i * (n - i + 1);
        ll up = 0;
        for (int j = 0; j < d.size(); j++)
        {
            d[j] = d[j] * mul + up;
            up = d[j] / Large;
            d[j] %= Large;

            if (j + 1 == d.size() && up) d.push_back(0);
        }
    }

    if (n % 2)
    {
        ll mul = n / 2 + 1;
        ll up = 0;
        for (int j = 0; j < d.size(); j++)
        {
            d[j] = d[j] * mul + up;
            up = d[j] / Large;
            d[j] %= Large;

            if (j + 1 == d.size() && up) d.push_back(0);
        }
    }

    reverse(d.begin(), d.end());
    cout << d[0];
    for (int i = 1; i < d.size(); i++) cout << setw(Large_Size) << setfill('0') << d[i];
}