#include <iostream>

using namespace std;

int main()
{
	int st[5];
	int avg=0;
	
	for(int i=0; i<5; i++)
	{
		cin>>st[i];
	}
	for(int i=0; i<5; i++)
	{
		if(st[i]<40)
		{
			st[i]=40;
		}
		avg=avg+st[i];
	}
	avg=avg/5;
	cout<<avg;
}