#include <iostream>
#define f for(i=0; i<n; i++)
int main(){int n,v,i;int arr[100];int cnt=0;std::cin>>n;f{std::cin>>arr[i];}std::cin>>v;f{if(arr[i]==v)cnt++;}std::cout<<cnt;}