#include <iostream>
#include <string.h>
#include <map>
using namespace std;
void fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(void)
{
    fast_io();
    map<int, string> mpInt;
    map<string, int> mpStr;
    int n, m, idx = 0;
    cin >> n >> m;
    while (n--)
    {
        idx++;
        string str;
        cin >> str;
        mpInt.insert(make_pair(idx, str));
        mpStr.insert(make_pair(str, idx));
    }
    while (m--)
    {
        char arr[21];
        cin >> arr;
        if (isdigit(arr[0]))
        {
            int intArr = atoi(arr);
            cout << mpInt.find(intArr)->second << "\n";
        }
        else
        {
            cout << mpStr.find(arr)->second << "\n";
        }
    }
}