#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int N;
   cin >> N;

   vector<ll> A(N);
   for(int i=0;i<N;i++) {
       cin >> A[i];
   }

   sort(A.begin(), A.end());

   int cnt = 0;
   for(int i=0;i<N;i++){
       bool is_good = false;
       int left = 0;
       int right = N-1;
       
       while(left < right) {
           if(left == i) {
               left++;
               continue;
           }
           if(right == i) {
               right--;
               continue;
           }
           
           ll sum = A[left] + A[right];
           if(sum == A[i]) {
               is_good = true;
               break;
           }
           else if(sum < A[i]) {
               left++;
           }
           else {
               right--;
           }
       }
       
       if(is_good) {
           cnt++;
       }
   }

   cout << cnt;
   return 0;
}