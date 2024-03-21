#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h,w,n,m;
    cin>>h>>w>>n>>m;
    int height=(h-1)/(n+1)+1;
    int width=(w-1)/(m+1)+1;
    cout<<height*width;
}