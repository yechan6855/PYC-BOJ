#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<ll> A(N);
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    ll B,C;
    cin>>B>>C;

    ll total_supervisors=0;
    for(int i=0; i<N; i++) {
        ++total_supervisors;
        A[i] -= B;
        if (A[i] > 0){
            total_supervisors+=ceil((double)A[i]/C);
        }
    }
    cout<<total_supervisors<<"\n";
}