#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N,M;
    cin>>N>>M;
    vector<long> S(N,0);
    vector<long> C(M,0);
    long answer = 0;
    cin>>S[0];
    
    for(int i = 1; i< N; i++){
        int temp = 0;
        cin>>temp;
        S[i]=S[i-1]+temp;
    }
    for(int i=0; i<N; i++){ // 합 배열의 모든 값에 % 연산 수행하기
        int remainer = S[i]%M;
        // 0 ~ i 까지의 구간 합 자체가 0일 때 정답에 더하기
        if(remainer == 0){
            answer++;
        }
        // 나머지가 같은 인덱스의 개수 세기
        C[remainer]++;
    }
    for(int i = 0; i<M; i++){
        if(C[i]>1){
            // 나머지가 같은 인덱스 중 2개를 뽑는 경우의 수를 더하기
            answer = answer + (C[i]*(C[i]-1)/2);
        }
    }
    cout<<answer<<"\n";
}