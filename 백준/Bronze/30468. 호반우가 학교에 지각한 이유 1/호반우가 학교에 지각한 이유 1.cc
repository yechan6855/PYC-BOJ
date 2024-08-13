#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a,b,c,d,n;
	cin>>a>>b>>c>>d>>n;
	int ans=a+b+c+d;
	if(ans<=n*4){
		cout<<n*4-ans;
	}else{
		cout<<0;
	}
}