#include <bits/stdc++.h>
#define endl "\n"
#define vi vector<int>
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

double x,y,c;

double solve(double mid){
    double a=sqrt(x*x-mid*mid);
    double b=sqrt(y*y-mid*mid);
    return (a*b)/(a+b);
}

int main() {
    io;
    cin>>x>>y>>c;
    double l=0,r=min(x,y);
    while(r-l>1e-6){
        double mid=(l+r)/2;
        if(solve(mid)>c){
            l=mid;
        }else{
            r=mid;
        }
    }

    cout<<fixed<<setprecision(3)<<l<<endl;
}