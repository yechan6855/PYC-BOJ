#include<iostream>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll x, y;
vector<pll> v;

ll CCW(pll A, pll B, pll C)
{
    ll tmp = A.X * B.Y + B.X * C.Y + C.X * A.Y;
    tmp -= B.X * A.Y + C.X * B.Y + A.X * C.Y;
    if (tmp > 0) return 1;
    else if (tmp == 0) return 0;
    else if (tmp < 0) return -1;
}

int solve(pll A, pll B, pll C, pll D)
{
    ll ans1 = CCW(A, B, C) * CCW(A, B, D);
    ll ans2 = CCW(C, D, A) * CCW(C, D, B);
    if (ans1 == 0 && ans2 == 0)
    {
        if (A > B) swap(A, B);
        if (C > D) swap(C, D);
        if (A <= D && B >= C) return 1;
        else return 0;
    }
    else
    {
        if (ans1 <= 0 && ans2 <= 0) return 1;
        else return 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++)
    {
        cin >> x >> y;
        v.push_back({ x,y });
    }
    cout << solve(v[0], v[1], v[2], v[3]);
}