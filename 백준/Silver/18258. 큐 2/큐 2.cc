#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int N, X;
string cmd;
queue<int> q;
int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> X;
            q.push(X);
            continue;
        }
        else if (cmd == "pop")
        {
            if (q.empty())
            {
                cout << -1;
            }
            else
            {
                cout << q.front();
                q.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << q.size();
        }
        else if (cmd == "empty")
        {
            cout << q.empty();
        }
        else if (cmd == "front")
        {
            if (q.empty())
            {
                cout << -1;
            }
            else
            {
                cout << q.front();
            }
        }
        else
        {
            if (q.empty())
            {
                cout << -1;
            }
            else
            {
                cout << q.back();
            }
        }
        cout << endl;
    }
    return 0;
}