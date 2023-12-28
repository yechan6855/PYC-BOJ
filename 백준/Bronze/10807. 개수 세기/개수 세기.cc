#include <iostream>

using namespace std;

int main()
{
	int n,v,i;
	int arr[100];
	int cnt=0;
	
	cin>>n;
	
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cin>>v;
	for(i=0; i<n; i++)
	{
		if(arr[i]==v)
		{
			cnt++;
		}
	}
	cout<<cnt;
}