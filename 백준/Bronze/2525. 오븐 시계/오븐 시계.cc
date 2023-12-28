#include <iostream>

using namespace std;

int main()
{
	int H,M,m;
	int a;
	
	cin>>H>>M;
	cin>>m;
	if(H==0)
	{
		H=24;
	}
	a=H*60+M+m;
	H=a/60;
	if(H==24)
	{
		H=0;
	}
	else if(H>24)
	{
		H=H-24;
	}
	M=a%60;
	cout<<H<<" "<<M;
}