#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10001
using namespace std;

int main()
{
    int k;
    double d1,d2;
    cin>>k;
    cin>>d1>>d2;
    cout<<k*k-((d1-d2)/2)*((d1-d2)/2);
}