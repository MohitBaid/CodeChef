#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int a[200000];
int func(int n)
{
	return (n*(n-1))%mod;
}
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,i,j,ans=1,l,h;
		cin>>n>>k;
		if((k*(k+1))/2>n)			cout<<-1<<endl;
		else if((k*(k+1))/2==n)		cout<<0<<endl;
		else
		{
			int f = k*(k+1)/2;
			int d = n - f;
			l=1;
			h=k;
			while(d>=k)
			{
				l++;
				h++;
				d=d-k;
			}
			int exc = -1;
			if(d!=0)
			{
				exc = h-d+1;
				h++;
			}
			for(i=l;i<=h;i++)
			{
				if(exc != i)
				{
					ans = ans * func(i);
					ans %= mod;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
