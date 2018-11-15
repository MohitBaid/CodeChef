#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i;	cin>>T;
	while(T--)
	{
		long long int n,a,b;	cin>>n>>a>>b;
		long long int powa=1,powb=1,pow=1,ca=0,cb=0;
		for(i=1;i<n;i++)	powa*=2,powb*=2,pow*=2;
		while(powa)
		{
			if(a>=powa)
			{
				a-=powa;
				ca++;
			}
			powa/=2;
		}
		while(powb)
		{
			if(b>=powb)
			{
				b-=powb;
				cb++;
			}	
			powb/=2;
		}
		int temp=(ca+cb);
		long long int ans=0;
		if(temp<=n)	
			for(i=n-1;i>=(n-temp);i--)	ans+=pow,pow/=2;
		else if(temp==2*n);		
		else
		{
			temp=temp%n;
			for(i=n-1;i>=temp;i--)		ans+=pow,pow/=2;
		}
		cout<<ans<<endl;
	}
}
