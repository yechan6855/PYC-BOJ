#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    cout<<fixed;
    cout.precision(9);
    
    double answer=9999;
    double X,Y,D,T; cin>>X>>Y>>D>>T;
    double d=sqrt(X*X+Y*Y);
    
    answer=min(answer,d);
    
    for(int i=1; ; i++)
    {
        if(i==1)
        {
            d=abs(D-d);
            answer=min(answer,d+T*i);
        }
        else
        {
            d=d-D;
            if(d<=0)
            {
                answer=min(answer,T*i);
                break;
            }
            answer=min(answer,abs(d)+T*i);
        }
    }
    cout<<answer;
}