#include <iostream>

using namespace std;

int main()
{
	int y;
	while(true){
		cin>>y;
		if(y>=1 && y<=4000)
		{
			break;
		}
	}
	if(y%4==0)
	{
		if(y%400==0 || y%100!=0)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
}